#include "minishell.h"

//int execBinary(t_msh *msh, char **execArr, t_cmd *cmd_s)
int execBinary(t_msh *msh, char **execArr)
{
	int pid;
	char **pathList;
	char *path_command;

	pathList = pipexSplit((getExportVar(&(msh->export_list), "PATH"))->value, ':');
	path_command = findCommand(pathList, execArr[0] );
	ft_freeStringsArr(pathList);
	if (path_command == NULL)
	{
		printError(execArr[0], 1);
		return (-1);
	}
	free(execArr[0]);
	execArr[0] = NULL;
	execArr[0] = path_command;
	pid = fork();
	if (pid == 0)
	{
		closeAllFds(msh->fd, msh->commands_num);
		execve(execArr[0], execArr, NULL);
		return (-1);
	}
	return (0);
}
