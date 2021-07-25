#include "pipex_bonus.h"

void	bonusClean(int **fd, t_bstruct *bStruct)
{
	bonusCloseAllFds(&fd, bStruct->commands_num);
	mFree(bStruct->pathList);
}
