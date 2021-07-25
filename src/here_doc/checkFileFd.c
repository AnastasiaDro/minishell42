#include "here_doc.h"

void	checkFileFd(int fileFd, char *name, int **fd, char **pathList)
{
	if (fileFd == -1)
	{
		printError(name, 0);
		fdPathListClean(fd, pathList);
		exit(1);
	}
}
