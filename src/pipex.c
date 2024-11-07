/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/11/07 19:14:22 by ndavenne         ###   ########.fr       */
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

char	*ft_strsjoin(const char *format, ...)
{
	va_list	args;
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

void	exec_cmd(t_pipex *p, char **envp, int cmd_index)
{
	char	*path;
	int		i;

	i = 0;
	while (p->env_paths[i] != NULL)
	{
		path = ft_pathjoin(p->env_paths[i], p->cmds[cmd_index][0]);
		execve(path, p->cmds[cmd_index], envp);
		i++;
	}
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


void	exec_all(t_pipex *p, char **envp)
{
	int	**pipefd;
	int	i;

	pipefd = malloc(sizeof(int *) * p->cmd_count - 1);
	i = 0;
	while (i < p->cmd_count - 1)
	{
		pipefd[i] = malloc(sizeof(int) * 2);
		if (pipe(pipefd[i])== -1)
			error();
		i++;
	}
	exec_last(p, envp, pipefd[p->cmd_count - 2]);
	exec_first(p, envp, pipefd[0]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;

	check_args(argc, argv);
	open_files(&p, argc, argv);
	p.env_paths = parse_env_paths(envp);
	p.cmds = parse_cmds(argc, argv);
	p.cmd_count = argc - 3;
	exec_all(&p, envp);
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

