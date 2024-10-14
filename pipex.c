/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 10:16:25 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/14 16:41:07 by ndavenne         ###   ########.fr       */
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
	env_paths = ft_split(*env, ':');
	return (env_paths);
}

char	***parse_cmds(int argc, char **argv)
{
	char	***cmds;
	int		i;

	i = 0;
	while (i + 2 < argc - 1)
	{
		cmds[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
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

void	exec_cmds(char ***cmds, char **env_paths, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
	{
		perror("pipe error");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		dup2();
		execve(ft_strjoin("/bin", "/cat"), cmds[0], envp);
	}
	else
	{
		wait(NULL);
	}
}

int	main(void)
{
	int		argc = 5;
	char	*argv[] = {"a.out", "infile", "cat", "wc -l", "outfile"};
	char	*envp[] = {"user=davdav", "PATH=/bin:/usr/bin"};
	char	**env_paths;
	char	***cmds;

	check_args(argc, argv);
	env_paths = parse_env_paths(envp);
	cmds = parse_cmds(argc, argv);
	exec_cmds(cmds, env_paths, envp);
	return (0);
}
