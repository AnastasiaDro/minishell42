/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 18:55:44 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/02 18:57:38 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "env_export_unset.h"

static void	getCMD(t_msh *msh, t_list *token)
{
	int		i;
	t_list	*tmp1;

	msh->commands_num = ft_lstsize(token);
	msh->cmd = malloc((msh->commands_num + 1) * sizeof(char *));
	msh->cmd[msh->commands_num] = NULL;
	tmp1 = token;
	i = 0;
	while (tmp1)
	{
		msh->cmd[i] = ft_strdup(tmp1->content);
		i++;
		tmp1 = tmp1->next;
	}
	ft_lstFree(token);
}

void	parser(t_msh *msh, char *line)
{
	char	*tmp;
	t_list	*token;

	token = NULL;
	while (line && *line)
	{
		while (*line == ' ')
			line++;
		while ((tmp = ft_strsep(&line, "|")) != NULL)
			ft_lstadd_back(&token, ft_lstnew(ft_strtrim(tmp, " ")));
	}
	getCMD(msh, token);
}
