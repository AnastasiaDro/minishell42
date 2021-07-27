//
// Created by Cesar Erebus on 7/25/21.
//

#include "minishell.h"

int execBinary(int i, t_msh *msh, int fdIn, int fdOut)
{
	int tmpFd;
	int pid;
	char	**execArr;
	char **pathList;

	tmpFd = checkHereDoc(i, msh);
	if (tmpFd == -1)
		return (-1);
	if (tmpFd)	//если у нас был << мы меняем источник ввода на временный файл
	{
		dup2(tmpFd, fdIn);
		close(tmpFd);
	}
	pathList = pipexSplit(findPath(msh->export_list), ':');

	if (pid == 0)
	{
		execArr = getExecArr(msh->cmd[i], pathList);
		if(!execArr)
		{
			printError(msh->cmd[i], 1);
			//тут бы очистить всё
			exit(1);
		}

		dup2(fdOut, STDOUT_FILENO);
		close(fdOut);
		execve(execArr[0], execArr, NULL);
		perror(NAME);
		exit(1);
	}
	return (pid);
}
