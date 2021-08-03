//
// Created by Cesar Erebus on 8/3/21.
//
#include "../minishell.h"

void ft_unset(t_msh *msh, char **names)
{
	t_en_list *envTmp;
	t_en_list *expTmp;

	envTmp = msh->env_list;
	expTmp = msh->export_list;
	deleteInList(&envTmp, names);
	deleteInList(&expTmp, names);
}
