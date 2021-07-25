#include "pipex_bonus.h"

void	initStruct(t_bstruct *bstruct, int argc, char *argv[], char **envp)
{
	bstruct->argc = argc;
	bstruct->flag = bonusCheckHereDoc(argv);
	bstruct->commands_num = argc - 3 - bstruct->flag;
	bstruct->argv = argv;
	bstruct->pathList = pipexSplit(findPath(envp), ':');
}
