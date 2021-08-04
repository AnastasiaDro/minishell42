/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envParsedLstNew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:36:49 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 13:37:31 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_en_list	*envParsedLstNew(char *name, char *value)
{
	t_en_list	*list;

	list = (t_en_list *)malloc(sizeof(t_en_list));
	if (!list)
		return (NULL);
	list->name = ft_strdup(name);
	if (value)
		list->value = ft_strdup(value);
	else
		list->value = NULL;
	list->next = NULL;
	return (list);
}
