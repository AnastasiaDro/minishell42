/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envDeleteVar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:14:13 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 20:26:28 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	delete_var(t_en_list *del, t_en_list *prev)
{
	prev->next = del->next;
	free(del->name);
	del->name = NULL;
	free(del->value);
	del->value = NULL;
	free(del);
	del = NULL;
}

void	deleteInList(t_en_list **list, char **names)
{
	int			i;
	t_en_list	*prev;
	t_en_list	*tmp;

	i = -1;
	while (names[++i])
	{
		prev = NULL;
		tmp = *list;
		while (tmp)
		{
			if (!ft_strcmp(names[i], tmp->name))
			{
				if (prev)
					delete_var(tmp, prev);
				else
					*list = (*list)->next;
				break ;
			}
			prev = tmp;
			tmp = tmp->next;
		}
	}
}
