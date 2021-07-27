#include "minishell.h"

int create_pipes(int arr_len, t_msh *msh)
{
	int	i;

	i = -1;
	msh->fd = malloc(sizeof(int *) * arr_len + 1);
	if (!msh->fd)
		return (0);
	msh->fd[arr_len] = NULL;
	while (++i < arr_len)
	{
		msh->fd[i] = malloc(sizeof (int) * 2);
		if (!(msh->fd[i]))
		{
			i--;
			while(i >= 0)
				free(msh->fd[i--]);
			free(msh->fd);
			return (0);
		}
	}
	return (1);
}
