/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:22:52 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:30:43 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	getNameValue(char **execArr, int i, char **name, char **value)
{
	char	*eq_ptr;

	eq_ptr = ft_strchr(execArr[i], '=');
	if (eq_ptr)
	{
		*eq_ptr = '\0';
		*name = ft_strdup(execArr[i]);
		*value = ft_strdup(eq_ptr + 1);
		*eq_ptr = '=';
	}
	else
	{
		*name = ft_strdup(execArr[i]);
		*value = NULL;
	}
}

int	cerExportHandler(t_msh *msh, char **execArr)
{
	char	*name;
	char	*value;
	int		i;

	i = 1;
	while (execArr[i])
	{
		getNameValue(execArr, i, &name, &value);
		envAddVariable(msh, name, value);
		i++;
	}
	return (1);
}
