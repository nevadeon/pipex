/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndavenne <ndavenne@student.42lehavre.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:07:54 by ndavenne          #+#    #+#             */
/*   Updated: 2024/12/04 13:07:23 by ndavenne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_open_fds(const char *where)
{
	int	fd;

	fd = 0;
	while (fd < 10)
	{
		if (fcntl(fd, F_GETFD) != -1)
			dprintf(2, "%s - FD %d is open (PID: %d)\n", where, fd, getpid());
		fd++;
	}
}

void	exec_cmd(t_pipex *p, char **envp, int cmd_index)
{
	char	*cmd_name;
	char	*path;
	int		i;

	cmd_name = p->cmds[cmd_index][CMD_NAME_INDEX];
	if (ft_strchr(cmd_name, '/'))
		execve(cmd_name, p->cmds[cmd_index], envp);
	else
	{
		i = 0;
		while (p->env_paths[i] != NULL)
		{
			cmd_name = p->cmds[cmd_index][CMD_NAME_INDEX];
			path = ft_strsjoin(3, p->env_paths[i], "/", cmd_name);
			execve(path, p->cmds[cmd_index], envp);
			i++;
		}
	}
}

void	exec_last(t_pipex *p, char **envp, int pipe_fd[2])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_error(E_FORK);
	if (pid == 0)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(p->in_fd);
		dup2(p->out_fd, STDOUT_FILENO);
		close(p->out_fd);
		exec_cmd(p, envp, p->cmd_count - 1);
		ft_dprintf(STDERR_FILENO, "Erreur execve: %s: %s\n",
			p->cmds[1][CMD_NAME_INDEX], strerror(errno));
		exit(errno);
	}
	close(pipe_fd[0]);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
		errno = WEXITSTATUS(status);
}

void	exec_first(t_pipex *p, char **envp, int pipe_fd[2])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		ft_error(E_FORK);
	if (pid == 0)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
		close(p->out_fd);
		dup2(p->in_fd, STDIN_FILENO);
		close(p->in_fd);
		exec_cmd(p, envp, 0);
		ft_dprintf(STDERR_FILENO, "Erreur execve: %s: %s\n",
			p->cmds[0][CMD_NAME_INDEX], strerror(errno));
		exit(errno);
	}
	close(pipe_fd[1]);
	waitpid(pid, &status, 0);
	if (WEXITSTATUS(status) != 0)
		errno = WEXITSTATUS(status);
}

void	executing(t_pipex *p, char **envp)
{
	int	pipefd[2];

	if (pipe(pipefd) == -1)
		ft_error(E_PIPE);
	exec_first(p, envp, pipefd);
	exec_last(p, envp, pipefd);
	close(p->in_fd);
	close(p->out_fd);
}
