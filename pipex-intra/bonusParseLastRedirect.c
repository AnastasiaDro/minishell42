#include "pipex.h"
#include "pipex_bonus.h"

int	bonusParseLastRedirect(int **fd, t_bstruct *bS)
{
	int		pid;
	char	*command;
	int		fileFd;
	char	**execArr;

	pid = fork();
	if (pid == 0)
	{
		command = bS->argv[bS->argc - 2];
		execArr = getExecArr(command, bS->pathList);
		if (!access(bS->argv[bS->argc - 1], 0))
			fileFd = open(bS->argv[bS->argc - 1], O_RDWR | O_APPEND);
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
