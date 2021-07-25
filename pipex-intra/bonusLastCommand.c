#include <unistd.h>
#include <sys/fcntl.h>
#include "pipex_bonus.h"

int	bonusLastCommand(int **fd, t_bstruct *bS)
{
	int		pid;
	char	*command;
	char	**execArr;
	int		fileFd;

	pid = fork();
	if (pid == 0)
	{
		command = bS->argv[bS->argc - 2];
		execArr = getExecArr(command, bS->pathList);
		if (!access(bS->argv[bS->argc - 1], 0))
			fileFd = open(bS->argv[bS->argc - 1], O_TRUNC | O_RDWR);
		else
			fileFd = open(bS->argv[bS->argc - 1], O_CREAT | O_RDWR, 0644);
		checkFileFd(fileFd, bS->argv[bS->argc - 1], bS, fd);
		dup2(fd[bS->commands_num - 1][0], STDIN_FILENO);
		dup2(fileFd, STDOUT_FILENO);
		close(fileFd);
		bonusClean(fd, bS);
		execve(execArr[0], execArr, NULL);
		perror(NAME);
		exit(1);
	}
	return (pid);
}
