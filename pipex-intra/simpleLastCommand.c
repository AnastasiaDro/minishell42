#include "pipex.h"

int	simpleLastCommand(int *fd, char *argv[], char **pathList)
{
	int		pid;
	char	*command;
	char	**execArr;
	int		fileFd;

	pid = fork();
	if (pid == 0)
	{
		command = argv[3];
		if (!access(argv[4], 0))
			fileFd = open(argv[4], O_TRUNC | O_RDWR);
		else
			fileFd = open(argv[4], O_CREAT | O_RDWR, 0644);
		simpleCheckFileFd(fileFd, argv, pathList);
		execArr = getExecArr(command, pathList);
		simpleCheckExecArr(execArr, pathList);
		dup2(fd[0], STDIN_FILENO);
		dup2(fileFd, STDOUT_FILENO);
		simpleCloseFds(fd, fileFd);
		mFree(pathList);
		execve(execArr[0], execArr, NULL);
		perror(NAME);
		exit(1);
	}
	return (pid);
}
