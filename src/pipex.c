/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/11/26 10:12:54 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Something happened, GLHF");
	exit(EXIT_FAILURE);
}

void	print_string_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

void	exec_cmd(t_pipex *p, char **envp, int cmd_index)
{
	char	*cmd_name;
	char	*path;
	int		i;

	cmd_name = p->cmds[cmd_index][CMD_NAME_INDEX];
	if (ft_strchr(cmd_name, '/'))
		execve(cmd_name, p->cmds[cmd_index], envp);
	else
	{
		i = 0;
		while (p->env_paths[i] != NULL)
		{
			cmd_name = p->cmds[cmd_index][CMD_NAME_INDEX];
			path = ft_strsjoin(3, p->env_paths[i], "/", cmd_name);
			execve(path, p->cmds[cmd_index], envp);
			i++;
		}
	}
	ft_dprintf(2, "pipex: command not found: %s", cmd_name);
}

void	exec_last(t_pipex *p, char **envp, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		dup2(p->out_fd, STDOUT_FILENO);
		close(p->out_fd);
		exec_cmd(p, envp, p->cmd_count - 1);
	}
}

void	exec_first(t_pipex *p, char **envp, int pipe_fd[2])
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		dup2(p->in_fd, STDIN_FILENO);
		close(p->in_fd);
		exec_cmd(p, envp, 0);
	}
}

void	executing(t_pipex *p, char **envp)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		error();
	exec_last(p, envp, pipefd);
	exec_first(p, envp, pipefd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	check_args(argc, argv);
	open_files(&p, argc, argv);
	p.env_paths = parse_env_paths(envp);
	p.cmds = parse_cmds(argc, argv);
	p.cmd_count = argc - 3;
	executing(&p, envp);
	// int i = -1;
	// while (p.cmds[++i] != NULL)
	// {
	// 	print_string_tab(p.cmds[i]);
	// 	printf("-----------\n");
	// }
	// print_string_tab(p.env_paths);
	// printf("%s\n", p.cmds[p.cmd_count - 1][0]);
	return (0);
}
