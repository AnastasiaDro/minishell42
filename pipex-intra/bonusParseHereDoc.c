#include "pipex.h"
#include "pipex_bonus.h"
#include "libft/libft.h"
#include "get_next_line/get_next_line.h"

int	bonusParseHereDoc(int **fd, t_bstruct *bStruct)
{
	char	*command;
	int		tmpFd;

	command = bStruct->argv[3];
	tmpFd = bonusGetTmpFile(bStruct->argv);
	if (tmpFd == -1 || bonusGetStdin(fd, command, tmpFd, bStruct) == -1 || \
		bonusParseMiddleCommands(fd, bStruct) == -1 || \
			bonusParseLastRedirect(fd, bStruct) == -1)
	{
		perror(NAME);
	}
	close(tmpFd);
	bonusClean(fd, bStruct);
	waitChildren();
	unlink("tmpFile");
	return (0);
}
