//
// Created by Cesar Erebus on 7/25/21.
//
#include <unistd.h>
#include <stdio.h>
#include "here_doc.h"
#include "../minishell.h"

//возвращает строку после гнл-а
int parseHereDoc(int i,  int out, t_msh *msh)
{
	int tmpFd;
	char *limiter;
	char *command;
	char **pathList;

	pathList = pipexSplit(findPath(msh->export_list), ' ');
	limiter = msh->cmd[i + 1];
	command = msh->cmd[i - 1];
	tmpFd = getTmpFile(limiter);
	if (tmpFd == -1 || getStdin(out, command, tmpFd, pathList))
		perror(NAME);
	close(tmpFd);
	unlink("tmpFile");
	return (out);
}
