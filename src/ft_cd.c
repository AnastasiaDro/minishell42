#include "minishell.h"

void	ft_cd(t_msh *msh, const char *path)
{
	chdir(path);
}