#include "pipex_bonus.h"

int	bonusParsePipesOnly(int **fd, t_bstruct *bStruct)
{
	if (parseFirstCommand(fd, bStruct) == -1 || bonusParseMiddleCommands(fd, bStruct) == -1 || \
			bonusLastCommand(fd, bStruct) == -1)
	{
		perror(NAME);
		bonusClean(fd, bStruct);
	}
	bonusClean(fd, bStruct);
	waitChildren();
	return (0);
}
