#include <sys/fcntl.h>
#include "here_doc.h"

int	getStdin(int out, char *command, int tmpFd, char **pathList)
{
	int		pid;
	char	**execArr;

	pid = fork();
	if (pid == 0)
	{
		tmpFd = open("tmpFile", O_RDONLY, 0644);
		dup2(tmpFd, STDIN_FILENO);
		execArr = getExecArr(command, pathList);
		dup2(out, STDOUT_FILENO);
		close(tmpFd);
		close(out);
		execve(execArr[0], execArr, NULL);
		perror(NAME);
		exit(1);
	}
	return (pid);
}
