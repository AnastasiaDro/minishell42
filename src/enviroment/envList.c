/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:20:24 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 13:30:29 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	env_lstsize(t_en_list *lst)
{
	int	i;

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
	int	len;

	len = env_lstsize(lst) - 1;
	while (lst && len--)
	{
		lst = lst->next;
	}
	return (lst);
}

void	env_lstadd_back(t_en_list **lst, t_en_list *new)
{
	t_en_list	*tmp;

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

t_en_list	*env_lstnew(char *str)
{
	t_en_list	*list;

	list = (t_en_list *)malloc(sizeof(t_en_list));
	if (!list)
		return (NULL);
	envSetNameValue(list, str);
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
