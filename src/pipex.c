/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/11/06 21:50:16 by ndavenne         ###   ########.fr       */
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

char	*ft_pathjoin(char const *s1, char const *s2)
{
	char	*joined;
	char	*joined_o;

	joined = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (joined == NULL)
		return (NULL);
	joined_o = joined;
	while (*s1 != '\0')
		*joined++ = *s1++;
	*joined++ = '/';
	while (*s2 != '\0')
		*joined++ = *s2++;
	*joined = '\0';
	return (joined_o);
}

void	exec_last_cmd(t_pipex *p, char **envp, int pipe_fd[2])
{
	char	*path;
	pid_t	pid;
	int		i;

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
		i = 0;
		while (p->env_paths[i] != NULL)
		{
			path = ft_pathjoin(p->env_paths[i], p->cmds[p->cmd_count - 1][0]);
			execve(path, p->cmds[p->cmd_count - 1], envp);
			i++;
		}
	}
}

void	exec_first_cmd(t_pipex *p, char **envp, int pipe_fd[2])
{
	char	*path;
	pid_t	pid;
	int		i;

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
		i = 0;
		while (p->env_paths[i] != NULL)
		{
			path = ft_pathjoin(p->env_paths[i], p->cmds[0][0]);
			execve(path, p->cmds[0], envp);
			i++;
		}
	}
}

void	exec_cmds(t_pipex *p, char **envp)
{
	int pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		error();
	exec_last_cmd(p, envp, pipe_fd);
	exec_first_cmd(p, envp, pipe_fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	check_args(argc, argv);
	open_files(&p, argc, argv);
	p.env_paths = parse_env_paths(envp);
	p.cmds = parse_cmds(argc, argv);
	p.cmd_count = argc - 3;
	exec_cmds(&p, envp);
	// print_string_tab(p.env_paths);
	// int i = -1;
	// while (p.cmds[++i] != NULL)
	// {
	// 	print_string_tab(p.cmds[i]);
	// 	printf("-----------\n");
	// }
	// printf("%s\n", p.cmds[p.cmd_count - 1][0]);
	return (0);
}

