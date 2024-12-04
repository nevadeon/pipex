/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:57:07 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/04 15:08:51 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "libndav.h"

// #define pipe(pipefd) \
// ({ \
// 	int ret = pipe(pipefd); \
// 	if (ret == -1) \
// 		fprintf(stderr, "pipe(%p) at %s:%d failed: %s\n", \
// 				pipefd, __FILE__, __LINE__, strerror(errno)); \
// 	else \
// 		fprintf(stderr, "pipe("#pipefd") = {%d,%d} at %s:%d\n", \
// 		pipefd[0], pipefd[1], \
// 		__FILE__, __LINE__); \
// 	ret; \
// })

// # define close(fd) \
// do \
// { \
// 	fprintf(stderr, "close(%d) at %s:%d\n", \
// 			fd, __FILE__, __LINE__); \
// 	close(fd); \
// } while (0)

// # define dup2(fd1, fd2) \
// do \
// { \
// 	fprintf(stderr, "dup2(%d, %d) at %s:%d\n", \
// 			fd1, fd2, __FILE__, __LINE__); \
// 	 if (dup2(fd1, fd2) == -1) \
// 	 	perror("dup2"); \
// } while (0)

# define CMD_NAME_INDEX 0

typedef enum e_error
{
	OK,
	E_FORK,
	E_PIPE
}	t_error;

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
void	executing(t_pipex *p, char **envp);

void	ft_error(t_error error_code);

#endif
