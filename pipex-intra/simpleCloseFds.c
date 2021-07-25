#include "pipex.h"

void	simpleCloseFds(int *fd, int fileFd)
{
	close(fd[0]);
	close(fd[1]);
	close(fileFd);
}
