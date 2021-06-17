#include "minishell.h"

#include "env_export_unset.h"

void	ft_init(t_msh *msh, char **envp)
 //       void	ft_init(t_msh *msh)
{
	msh->fd = 0;
	msh->len = 0;
	msh->line = NULL;
	msh->quote = 0;
	//я добавила
	msh->envp_list = NULL;
	msh->envp_len = init_envp_list(&(msh->envp_list), envp);
}

