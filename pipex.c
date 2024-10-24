/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/23 16:23:26 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error()
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

// void	exec_cmds(char ***cmds, char **env_paths, char **envp)
// {
// 	char	**env_paths2;
// 	int		pipefd[2];
// 	pid_t	pid;
// 	int fd;

// 	env_paths2 = env_paths;
// 	if (pipe(pipefd) == -1)
// 	{
// 		perror("pipe error");
// 		exit(EXIT_FAILURE);
// 	}
// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror("fork error");
// 		exit(EXIT_FAILURE);
// 	}
// 	if (pid == 0)
// 	{
// 		close(pipefd[0]);
// 		dup2(pipefd[1], STDOUT_FILENO);
// 		close(pipefd[1]);
// 		fd = open("infile", O_RDONLY);
// 		dup2(fd, STDIN_FILENO);
// 		close(fd);
// 		fd = 0;
// 		while (*env_paths != NULL)
// 		{
// 			execve(ft_pathjoin(*env_paths, cmds[0][0]), cmds[0], envp);
// 			env_paths++;
// 		}
// 		printf("command 1 failure\n");
// 		exit(EXIT_FAILURE);
// 	}
// 	else
// 	{
// 		pid = fork();
// 		if (pid == -1)
// 		{
// 			perror("pipe error");
// 			exit(1);
// 		}
// 		if (pid == 0)
// 		{
// 			close(pipefd[1]);
// 			dup2(pipefd[0], STDIN_FILENO);
// 			close(pipefd[0]);
// 			fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 			dup2(fd, STDOUT_FILENO);
// 			close(fd);
// 			while (*env_paths2 != NULL)
// 			{
// 				execve(ft_pathjoin(*env_paths2, cmds[1][0]), cmds[1], envp);
// 				env_paths2++;
// 			}
// 		}
// 	}
// }

int	*exec_first_cmd(t_pipex *p, char **envp)
{
	pid_t	pid;
	char	*path;
	int		pipe_fd[2];
	int		i;

	if (pipe(pipe_fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(p->in_fd, STDIN_FILENO);
		close(p->in_fd);
		i = 0;
		while(p->env_paths[i] != NULL)
		{
			path = ft_pathjoin(p->env_paths[i], p->cmds[0][0]);
			execve(path, p->cmds[0], envp);
			i++;
		}
	}
}

void	exec_last_cmd(t_pipex *p, char **envp)
{
	pid_t	pid;
	char	*path;
	int		pipe_fd[2];
	int		i;

	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(p->out_fd, STDOUT_FILENO);
		close(p->out_fd);
		i = 0;
		while(p->env_paths[i] != NULL)
		{
			path = ft_pathjoin(p->env_paths[i], p->cmds[0][0]);
			execve(path, p->cmds[0], envp);
			i++;
		}
	}
}

void	exec_cmds(t_pipex *p, char **envp)
{
	pid_t	pid;
	char	*path;
	int		pipe_fd[2];
	int		i;

	if (pipe(pipe_fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error;
	else if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(p->in_fd, STDIN_FILENO);
		close(p->in_fd);
		i = 0;
		while(p->env_paths[i] != NULL)
		{
			path = ft_pathjoin(p->env_paths[i], p->cmds[0][0]);
			execve(path, p->cmds[0], envp);
			i++;
		}
	}
	while ()
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	p;
	void	*arena_ptr;

	check_args(argc, argv);
	open_files(&p, argc, argv);
	arena_ptr = ft_arena(0);
	p.env_paths = parse_env_paths(envp);
	p.cmds = parse_cmds(argc, argv);
	p.cmd_count = argc - 3;
	exec_cmds(&p, envp);
	free_arena(arena_ptr);
	return (0);
}

	// print_string_tab(p.env_paths);
	// int i = -1;
	// while (p.cmds[++i] != NULL)
	// {
	// 	print_string_tab(p.cmds[i]);
	// 	printf("-----------\n");
	// }
	// print_string_tab(envp);
