#include "minishell.h"

void	ft_pwd(t_msh *msh, char dir, size_t len)
{
	getcwd(dir, len);
	write(msh->fd, dir, len);
}