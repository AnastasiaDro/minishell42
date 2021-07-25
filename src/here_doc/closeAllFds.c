//
// Created by Cesar Erebus on 7/25/21.
//

#include <unistd.h>
#include <stdlib.h>

int closeFreeAllFds(int **fd)
{
	int i;

	i = 0;
	while (fd[i])
	{
		close(fd[i][0]);
		close(fd[i][1]);
		free(fd[i]);
		i++;
	}
	return (1);
}