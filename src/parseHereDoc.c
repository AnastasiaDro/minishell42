/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseHereDoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:16:51 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 23:03:28 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	getTmpFile(char **tokens, int *j)
{
	char	*line;
	int		tFileFd;
	char	*tmp;
	char	*limiter;

	limiter = ft_strdup(tokens[(*j) + 1]);
	line = NULL;
	tFileFd = open("tmpFile", O_CREAT | O_RDWR, 0644);
	write(1, "> ", 2);
	get_next_line(STDIN_FILENO, &line);
	while (ft_strcmp(line, limiter))
	{
		tmp = line;
		write(tFileFd, line, ft_strlen(line));
		write(tFileFd, "\n", 1);
		write(1, "> ", 2);
		get_next_line(STDIN_FILENO, &line);
		free(tmp);
	}
	free(line);
	free(limiter);
	close(tFileFd);
	return (tFileFd);
}

int	parseHereDoc(t_cmd *cmd_s, int *j)
{
	cmd_s->here_doc = 1;
	getTmpFile(cmd_s->cmdTokens, j);
	*cmd_s->fileInFd = open("tmpFile", O_RDONLY, 0644);
	(*j) += 1;
	return (HERE_DOC);
}
