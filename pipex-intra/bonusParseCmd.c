#include <unistd.h>
#include "pipex_bonus.h"
#include "pipex.h"
#include "libft/libft.h"

int	bonusParseCmd(int ***fd, int current_index, t_bstruct *bStruct)
{
	int		**tmp;
	char	*command;
	char	**execArr;
	int		coef;

	if (bStruct->flag == HERE_DOC)
		coef = 3;
	else
		coef = 2;
	command = (bStruct->argv)[coef + current_index];
	execArr = getExecArr(command, bStruct->pathList);
	tmp = *fd;
	if (execArr == NULL)
	{
		bonusCloseAllFds(fd, bStruct->commands_num);
		exit(0);
	}
	dup2(tmp[current_index][0], STDIN_FILENO);
	dup2(tmp[current_index + 1][1], STDOUT_FILENO);
	bonusCloseAllFds(fd, bStruct->commands_num);
	execve(execArr[0], execArr, NULL);
	perror(NAME);
	exit(1);
}
