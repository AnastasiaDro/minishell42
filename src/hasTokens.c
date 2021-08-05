/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasTokens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:29:03 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 17:37:05 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	findControlSym(char *s)
{
	if (s && ft_strcmp(s, ">>") && ft_strcmp(s, ">") && ft_strcmp(s, "<") && \
		ft_strcmp(s, "<<"))
	{
		return (1);
	}
	return (0);
}

char	**hasTokens(t_cmd *cmd_s)
{
	int		j;
	int		u;
	int		end;
	int		arrLen;
	char	**execArr;

	j = 0;
	execArr = NULL;
	arrLen = ft_arrlen(cmd_s->cmdTokens);
	while (j < arrLen)
	{
		while (cmd_s->cmdTokens[j] && check_ctrl_symbol(cmd_s, &j))
			j++;
		end = j;
		while (findControlSym(cmd_s->cmdTokens[end]))
			end++;
		execArr = ft_calloc(sizeof(char *), (end - j + 1));
		u = -1;
		while (++u < (end - j))
			execArr[u] = ft_strdup(cmd_s->cmdTokens[u + j]);
		j = end;
		while (cmd_s->cmdTokens[j] && check_ctrl_symbol(cmd_s, &j))
			j++;
	}
	return (execArr);
}
