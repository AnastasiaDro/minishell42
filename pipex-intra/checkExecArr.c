#include "pipex_bonus.h"

void	checkExecArr(char **execArr, int **fd, t_bstruct *bS)
{
	if (!execArr)
	{
		bonusClean(fd, bS);
		exit(1);
	}
}
