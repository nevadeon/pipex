/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/22 17:23:22 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libndav.h"

char	**parse_env_paths(char **env)
{
	char	**env_paths;

	while (*env != NULL)
	{
		if (ft_strncmp(*env, "PATH=", 5) == 0)
		{
			*env = *env + 5;
			break ;
		}
		env++;
	}
	if (*env == NULL)
		return (NULL);
	env_paths = ft_split(*env, ':');
	return (env_paths);
}

char	***parse_cmds(int argc, char **argv)
{
	char	***cmds;
	int		nb_cmds;
	int		i;

	nb_cmds = argc - 3;
	cmds = (char ***)malloc(sizeof(char **) * (nb_cmds + 1));
	i = 0;
	while (i < nb_cmds)
	{
		cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	cmds[nb_cmds] = NULL;
	return (cmds);
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

void	check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("not enough arguments\n");
		exit(1);
	}
	if (access(argv[1], R_OK) != 0)
	{
		printf("no permission to read infile\n");
		exit (1);
	}
	if (access(argv[4], W_OK) != 0)
	{
		printf("no permission to write to outfile\n");
		exit (1);
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

void	exec_cmds(char ***cmds, char **env_paths, char **envp)
{
	char	**env_paths2;
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;

	env_paths2 = env_paths;
	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	int fd = open("infile", O_RDONLY);
	dup2(fd, STDIN_FILENO);
	close(fd);
	pid1 = fork();
	if (pid1 == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		while (*env_paths != NULL)
		{
			execve(ft_pathjoin(*env_paths, cmds[0][0]), cmds[0], envp);
			env_paths++;
		}
		printf("command 1 failure\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			perror("pipe error");
			exit(1);
		}
		if (pid2 == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			while (*env_paths2 != NULL)
			{
				execve(ft_pathjoin(*env_paths2, cmds[1][0]), cmds[1], envp);
				env_paths2++;
			}
		}
	}
}

int	main(int argc, char **argv, char **envp)
{
	argc = 5;
	char	*argtest[] = {"a.out", "infile", "cat", "wc -l", "outfile"};
	char	**env_paths;
	char	***cmds;

	check_args(argc, argtest);
	env_paths = parse_env_paths(envp);
	cmds = parse_cmds(argc, argtest);

	//print test
	// print_string_tab(env_paths);
	// int i = -1;
	// while (cmds[++i] != NULL)
	// {
	// 	print_string_tab(cmds[i]);
	// 	printf("-----------\n");
	// }
	// print_string_tab(envp);

	exec_cmds(cmds, env_paths, envp);
	return (0);
}
