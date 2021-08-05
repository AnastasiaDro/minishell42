/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeEnList.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:19:37 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:19:38 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_freeEnList(t_en_list *list)
{
	t_en_list	*tmp;
	t_en_list	*tmpP;

	tmp = list;
	while (tmp)
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
