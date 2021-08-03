/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envPrintLists.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:13:44 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 20:31:33 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_print_export( t_msh *msh)
{
	t_en_list	*vars;
	char		*value;

	vars = msh->export_list;
	while (vars)
	{
		value = vars->value;
		if (value != NULL)
			printf("declare -x %s=\"%s\"\n", vars->name, vars->value);
		else
		{
			if (vars->name)
				printf("declare -x %s\n", vars->name);
		}
		vars = vars->next;
	}
	return (1);
}

int	ft_print_env(t_msh *msh)
{
	t_en_list	*vars;
	char		*value;

	vars = msh->env_list;
	while (vars)
	{
		value = vars->value;
		if (value != NULL)
			printf("%s=\"%s\"\n", vars->name, vars->value);
		vars = vars->next;
	}
	return (1);
}
