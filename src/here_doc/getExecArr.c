#include <string.h>
#include "here_doc.h"

char	**getExecArr(char *command, char **pathList)
{
	int		arrLen;
	char	**execArr;
	char	*path_command;

	execArr = execArrSplit(command, ' ', &arrLen);
	path_command = findCommand(pathList, command);
	if (path_command == NULL)
	{
		printError(command, 1);
		return (NULL);
	}
	free(execArr[0]);
	execArr[0] = NULL;
	execArr[0] = path_command;
	return (execArr);
}
