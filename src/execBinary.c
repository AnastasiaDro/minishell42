//
// Created by Cesar Erebus on 7/29/21.
//

#include "minishell.h"

int execBinary(t_msh *msh, char **execArr, t_cmd *cmd_s)
{
	int pid;
	char *binaryName;
	char **pathList;
	char *path_command;

	//найти бинарник
	pathList = pipexSplit((getExportVar(&(msh->export_list), "PATH"))->value, ':');
	path_command = findCommand(pathList, execArr[0] );
	if (path_command == NULL)
	{
		printError(execArr[0], 1);
		return (-1);
	}

	execArr[0] = path_command;

	pid = fork();
	if (pid == 0)
	{
		execve(execArr[0], execArr, NULL);
	}
	return (-1);
}
