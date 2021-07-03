#include "minishell.h"

int	env_lstsize(t_en_list *lst)
{
	int i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_en_list	*env_lstlast(t_en_list *lst)
{
	int len;

	len = env_lstsize(lst) - 1;
	while (lst && len--)
	{
		lst = lst->next;
	}
	return (lst);
}


void	env_lstadd_back(t_en_list **lst, t_en_list *new)
{
	t_en_list *tmp;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		tmp = env_lstlast(*lst);
		tmp->next = new;
	}
}


void    set_name_value(t_en_list *list, char *str)
{
    int start;
    int end;
    int len;
    char *new_str;

    new_str = ft_strdup(str);
    
    start = 0;
    end = 0;
    len = ft_strlen(str);
    while (new_str[end] && new_str[end] != '=')
        end++;
    if (end == len)
    {
        list->name = ft_strdup(new_str);
        list->value = NULL;
    } 
    else
    {
        new_str[end] = '\0';
        list->name = ft_strdup(new_str);
        new_str[end] = '=';
        list->value = ft_strdup(&new_str[end + 1]);
    }
    free(new_str);
    new_str = NULL;
}


t_en_list		*env_lstnew(char *str)
{
	t_en_list	*list;

	if (!(list = (t_en_list *)malloc(sizeof(t_en_list))))
		return (NULL);
    set_name_value(list, str);
	list->next = NULL;
	return (list);
}

t_en_list       *env_parsed_lstnew(char *name, char *value)
{
    t_en_list	*list;

    if (!(list = (t_en_list *)malloc(sizeof(t_en_list))))
        return (NULL);
    list->name = name;
    list->value = value;
    list->next = NULL;
    return (list);
}

void	env_lstadd_front(t_en_list **lst, t_en_list *new)
{
	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	new->next = *lst;
	*lst = new;
}