/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:07 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/23 11:44:46 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libndav.h"

# define ARENA_SIZE 100000

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef unsigned int t_uint;

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	**env_paths;
	char	***cmds;
	t_uint	cmd_count;
}	t_pipex;

void	*ft_arena(size_t size);
void	free_arena(void *ptr);

void	check_args(int argc, char **argv);
char	**parse_env_paths(char **env);
char	***parse_cmds(int argc, char **argv);

#endif
