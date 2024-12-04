/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:22:06 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/04 14:52:31 by ndavenne         ###   ########.fr       */
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
	cmds = ft_arena_alloc(sizeof(char **) * (nb_cmds + 1));
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
	if (argc != 5)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./pipex infile cmd1 cmd2 outfile\n");
		ft_free_arena();
		exit(EXIT_FAILURE);
	}
	if (access(argv[1], R_OK) != 0)
	{
		perror("Erreur accessing infile");
		ft_free_arena();
		exit(errno);
	}
	if (access(argv[argc - 1], W_OK) != 0)
	{
		perror("Erreur accessing outfile");
		ft_free_arena();
		exit(errno);
	}
}

void	open_files(t_pipex *p, int argc, char **argv)
{
	p->in_fd = open(argv[1], O_RDONLY);
	if (p->in_fd == -1)
	{
		perror("Erreur opening infile");
		ft_free_arena();
		exit(errno);
	}
	p->out_fd = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (p->out_fd == -1)
	{
		perror("Erreur opening outfile");
		ft_free_arena();
		exit(errno);
	}
}
