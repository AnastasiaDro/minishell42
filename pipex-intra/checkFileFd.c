#include "pipex_bonus.h"

void	checkFileFd(int fileFd, char *name, t_bstruct *bS, int **fd)
{
	if (fileFd == -1)
	{
		printError(name, 0);
		bonusClean(fd, bS);
		exit(0);
	}
}
