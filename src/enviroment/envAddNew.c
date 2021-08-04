/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envAddNew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:14:22 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 20:18:49 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "../../libft/libft.h"
#include "../minishell.h"
#include "enviroment.h"
#define EXP_PREFIX "declare -x "

void	envInsertToList(t_en_list *prev, t_en_list *fol, t_en_list *new)
{
	prev->next = new;
	new->next = fol;
}

void	envExportAddNew(t_en_list *export_list, char *name, char *value)
{
	t_en_list	*tmp;
	t_en_list	*previous;

	previous = export_list;
	tmp = export_list->next;
	if (ft_strncmp(previous->name, name, ft_strlen(name)) >= 0)
	{
		env_lstadd_front(&export_list, envParsedLstNew(name, value));
		return ;
	}
	while (tmp)
	{
		if (ft_strncmp(tmp->name, name, ft_strlen(name)) > 0)
		{
			envInsertToList(previous, tmp, envParsedLstNew(name, value));
			return ;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	env_lstadd_back(&export_list, envParsedLstNew(name, value));
}

t_en_list	*envAddExportList(t_msh *msh, char *name, char *value)
{
	t_en_list	*p;

	p = getExportVar(&msh->export_list, name);
	if (p)
	{
		p->value = value;
	}
	else
		envExportAddNew(msh->export_list, name, value);
	return (p);
}

void	envAddEnvList(t_msh *msh, char *name, char *value, t_en_list *flag)
{
	t_en_list	*p;

	if (!flag)
		env_lstadd_back(&(msh->env_list), envParsedLstNew(name, value));
	else
	{
		p = getExportVar(&msh->env_list, name);
		p->value = value;
	}
}

void	envAddVariable(t_msh *msh, char *name, char *value)
{
	t_en_list	*flag;

	flag = envAddExportList(msh, name, value);
	envAddEnvList(msh, name, value, flag);
}
