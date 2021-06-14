#include "minishell.h"

void	ft_pwd(t_msh *msh, char *dir)
{
	int	len = ft_strlen(dir);
	dir = getcwd(dir, len + 1);
	write(msh->fd, dir, len);
}