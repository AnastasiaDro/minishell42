#include "minishell.h"

void	ft_init(t_msh *msh)
{
	msh->fd = 0;
	msh->len = 0;
	msh->quote = 0;
}
