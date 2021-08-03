/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envUnset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:13:35 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 20:13:36 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void envUnset(t_msh *msh, char **names)
{
	t_en_list *envTmp;
	t_en_list *expTmp;

	envTmp = msh->env_list;
	expTmp = msh->export_list;
	deleteInList(&envTmp, names);
	deleteInList(&expTmp, names);
}
