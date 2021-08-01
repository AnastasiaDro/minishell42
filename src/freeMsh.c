//
// Created by Cesar Erebus on 8/1/21.
//
#include "minishell.h"

void freeMsh(t_msh *msh)
{
	ft_freeEnList(msh->export_list);
	ft_freeEnList(msh->env_list);
	ft_freeStringsArr(msh->cmd);
}