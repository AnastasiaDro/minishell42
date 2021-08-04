/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envSetNameVal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:37:56 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 20:31:49 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	envSetNameValue(t_en_list *list, char *str)
{
	int		end;
	int		len;
	char	*new_str;

	new_str = ft_strdup(str);
	end = 0;
	len = (int)ft_strlen(str);
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
