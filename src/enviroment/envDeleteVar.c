#include "../minishell.h"

void delete_var(t_en_list *del, t_en_list *prev)
{
	prev->next = del->next;
	free(del->name);
	free(del->value);
	free(del);
	del = NULL;
}

void deleteInList(t_en_list **list, char **names)
{
	int 		i;
	t_en_list 	*prev;
	t_en_list 	*tmp;

	prev = NULL;
	i = -1;
	while (names[++i])
	{
		tmp = *list;
		while(tmp)
		{
			if (!ft_strcmp(names[i], tmp->name))
			{
				if (prev)
				{
					delete_var(tmp, prev);
					break;
				}
				else
				{
					*list = (*list)->next;
					break;
				}
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
