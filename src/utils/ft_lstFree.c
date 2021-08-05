/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstFree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:19:49 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:19:50 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"

void	ft_lstFree(t_list *list)
{
	t_list	*tmp;
	t_list	*tmpP;

	tmp = list;
	while (tmp)
	{
		tmpP = tmp;
		free(tmp->content);
		tmp->content = NULL;
		tmp = tmp->next;
		free(tmpP);
		tmpP = NULL;
	}
}
