/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envUnset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:13:35 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 20:32:01 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	envUnset(t_msh *msh, char **names)
{
	deleteInList(&msh->env_list, names);
	deleteInList(&msh->export_list, names);
}
