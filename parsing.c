/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:22:06 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/23 14:28:02 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void	check_args(int argc, char **argv)
{
	if (argc < 5)
	{
		printf("Usage: ./pipex infile cmd1 cmd2 ... outfile\n");
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0)
	{
		perror("Infile error");
		exit (EXIT_FAILURE);
	}
	if (access(argv[argc - 1], W_OK) != 0)
	{
		perror("Outfile error");
		exit (EXIT_FAILURE);
	}
}

void	open_files(t_pipex *p, int argc, char **argv)
{
	p->in_fd = open(argv[1], O_RDONLY);
	if (p->in_fd == -1)
	{
		perror("error when opening infile");
		exit(EXIT_FAILURE);
	}
	p->out_fd = open(argv[argc- 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if(p->out_fd == -1)
	{
		perror("error when opening outfile");
		exit(EXIT_FAILURE);
	}
}
