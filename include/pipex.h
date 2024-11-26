/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:07 by ndavenne          #+#    #+#             */
/*   Updated: 2024/11/26 09:59:36 by ndavenne         ###   ########.fr       */
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

#define CMD_NAME_INDEX 0

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	char	**env_paths;
	char	***cmds;
	int		cmd_count;
}	t_pipex;

void	check_args(int argc, char **argv);
char	**parse_env_paths(char **env);
char	***parse_cmds(int argc, char **argv);
void	open_files(t_pipex *p, int argc, char **argv);

#endif
