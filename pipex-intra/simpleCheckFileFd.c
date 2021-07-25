#include "pipex.h"

void	simpleCheckFileFd(int fileFd, char *argv[], char **pathList)
{
	if (fileFd == -1)
	{
		printError(argv[1], 0);
		mFree(pathList);
		exit(1);
	}
}
