/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getExportVar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:58:04 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:58:25 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_en_list	*getExportVar(t_en_list **export, char *key_name)
{
	t_en_list	*tmp;

	tmp = *export;
	while (tmp)
	{
		if (!ft_strcmp(key_name, tmp->name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
