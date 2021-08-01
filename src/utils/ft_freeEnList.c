//
// Created by Cesar Erebus on 8/1/21.
//

#include "../minishell.h"

void ft_freeEnList(t_en_list *list)
{
	t_en_list *tmp;
	t_en_list *tmpP;

	tmp = list;
	while(tmp)
	{
		tmpP = tmp;
		free(tmp->name);
		free(tmp->value);
		tmp->name = NULL;
		tmp->value = NULL;
		tmp = tmp->next;
		free(tmpP);
		tmpP = NULL;
	}
}