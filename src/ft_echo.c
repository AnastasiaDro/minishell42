#include "minishell.h"

void	ft_echo(t_msh *msh, char *arguments)
{
	write(msh->fd, arguments, sizeof(arguments));
}