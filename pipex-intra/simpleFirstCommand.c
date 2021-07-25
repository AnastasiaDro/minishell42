#include "pipex.h"

int	simpleFirstCommand(int *fd, char *argv[], char **pathList)
{
	int		pid;
	char	*command;
	char	**execArr;
	int		fileFd;

	pid = fork();
	if (pid == 0)
	{
		command = argv[2];
		fileFd = open(argv[1], O_RDWR);
		simpleCheckFileFd(fileFd, argv, pathList);
		execArr = getExecArr(command, pathList);
		simpleCheckExecArr(execArr, pathList);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fileFd, STDIN_FILENO);
		simpleCloseFds(fd, fileFd);
		mFree(pathList);
		execve(execArr[0], execArr, NULL);
		perror(NAME);
		exit(-1);
	}
	return (pid);
}
