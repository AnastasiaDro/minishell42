//
// Created by Cesar Erebus on 8/1/21.
//
#include "../../libft/libft.h"

void ft_lstFree(t_list *list)
{
	t_list *tmp;
	t_list *tmpP;

	tmp = list;
	while(tmp)
	{
		tmpP = tmp;
		free(tmp->content);
		tmp->content = NULL;
		tmp = tmp->next;
		free(tmpP);
		tmpP = NULL;
	}
}
