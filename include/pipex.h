/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <github@noedavenne.aleaas.coms    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:07 by ndavenne          #+#    #+#             */
/*   Updated: 2024/10/27 19:13:26 by ndavenne         ###   ########.fr       */
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
