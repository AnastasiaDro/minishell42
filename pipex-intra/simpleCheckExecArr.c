#include "pipex.h"

void	simpleCheckExecArr(char **execArr, char **pathList)
{
	if (!execArr)
	{
		mFree(pathList);
		exit(1);
	}
}
