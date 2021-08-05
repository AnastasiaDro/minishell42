/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseRedirects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:14:40 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:15:52 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/file.h>
#include "minishell.h"

int	getRedLargeFd(char **tokens, int *j)
{
	int		fileFd;
	char	*fileName;

	fileName = ft_strdup(tokens[(*j) + 1]);
	fileFd = open(fileName, O_TRUNC | O_CREAT | O_RDWR, 0644);
	free(fileName);
	return (fileFd);
}

int	parseRedLarge(t_cmd *cmd_s, int *j)
{
	int	tmp;

	if (cmd_s->red_larg != 1)
	{
		cmd_s->red_larg = 1;
		*cmd_s->fileOutFd = getRedLargeFd(cmd_s->cmdTokens, j);
		(*j) += 1;
	}
	else
	{
		tmp = *cmd_s->fileOutFd;
		*cmd_s->fileOutFd = getRedLargeFd(cmd_s->cmdTokens, j);
		close(tmp);
		(*j) += 1;
	}
	return (RED_LARG);
}

int	parseDoubleLarge(t_cmd *cmd_s, int *j)
{
	cmd_s->double_larg = 1;
	*cmd_s->fileOutFd = open(cmd_s->cmdTokens[(*j) + 1], \
			O_CREAT | O_RDWR | O_APPEND, 0644);
	(*j) += 1;
	return (DOUBLE_LARG);
}

int	parseRedSmall(t_cmd *cmd_s, int *j)
{
	cmd_s->red_smal = 1;
	*cmd_s->fileInFd = open(cmd_s->cmdTokens[(*j) + 1], O_RDONLY);
	(*j) += 1;
	return (RED_SMALL);
}
