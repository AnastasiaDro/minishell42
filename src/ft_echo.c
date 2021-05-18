#include "minishell.h"

void	ft_echo(t_msh *msh, int arguments)
{
	write(msh->fd, arguments, sizeof(arguments));
}