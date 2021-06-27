#include "minishell.h"

#include "env_export_unset.h"

void	ft_init(t_msh *msh, char **envp)
{
	msh->fd = 0;
	msh->len = 0;
	msh->line = NULL;
	msh->quote = 0;
	msh->envp_arr = envp;
	//я добавила
	msh->envp_list = malloc(sizeof(t_en_list) * 1);
	msh->envp_len = init_envp_list(envp, &(msh->envp_list));
}

