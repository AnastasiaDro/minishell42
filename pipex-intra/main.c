#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"

int	main(int argc, char *argv[], char **envp)
{
	char	**pathList;
	int		pfd[2];

	if (argc != 5)
		return ((int)write(1, ARGNUM_ERR, (int)ft_strlen(ARGNUM_ERR)));
	pathList = pipexSplit(findPath(envp), ':');
	if (pipe(pfd) == -1)
	{
		perror(NAME);
		exit(1);
	}
	if (simpleFirstCommand(pfd, argv, pathList) == -1 || \
			simpleLastCommand(pfd, argv, pathList) == -1)
	{
		perror(NAME);
	}
	close(pfd[0]);
	close(pfd[1]);
	mFree(pathList);
	waitChildren();
}
