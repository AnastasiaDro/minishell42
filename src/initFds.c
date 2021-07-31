//
// Created by Cesar Erebus on 7/31/21.
//

#include "minishell.h"

int initFds(t_msh *msh)
{
	int i;

	i = 0;
	msh->fd = malloc(sizeof(int *) * msh->commands_num);
	while (i < msh->commands_num)
	{
		msh->fd[i] = malloc(sizeof(int) * 2);
		pipe(msh->fd[i]);
		i++;
	}
	return (i);
}