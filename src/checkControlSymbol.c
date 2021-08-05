/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkControlSymbol.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:17:44 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:18:07 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	checkCtrlSymbol(t_cmd *cmd_s, int *j)
{
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "<<"))
		return (parseHereDoc(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "<"))
		return (parseRedSmall(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], ">>"))
		return (parseDoubleLarge(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], ">"))
		return (parseRedLarge(cmd_s, j));
	return (0);
}
