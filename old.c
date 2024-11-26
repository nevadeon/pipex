#include "pipex.h"

void	exec_basic(t_pipex *p, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (pipe(pipefd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		close(pipefd[1]);
		dup2(p->in_fd, STDIN_FILENO);
		close(p->in_fd);
		exec_cmd(p, envp, 0);
	}
	else
	{
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
		{
			close(pipefd[1]);
			dup2(pipefd[0], STDIN_FILENO);
			close(pipefd[0]);
			dup2(p->out_fd, STDOUT_FILENO);
			close(p->out_fd);
			exec_cmd(p, envp, 1);
		}
	}
}
