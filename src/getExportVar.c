//
// Created by Cesar Erebus on 7/29/21.
//

#include "minishell.h"

t_en_list *getExportVar(t_en_list **export, char *key_name)
{
	t_en_list *tmp;

	tmp = *export;
	while(tmp)
	{
		if (!ft_strcmp(key_name, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}