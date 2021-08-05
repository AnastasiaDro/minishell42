/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:06:25 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 21:10:40 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

const char	*getValue(t_en_list *export_list, const char *key)
{
	t_en_list	*tmp;

	tmp = export_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, key))
			return (tmp->value);
		tmp = tmp->next;
		
	}
	return (NULL);
}

void	ft_init(t_msh *msh, char **envp)
{
	char	*s1;
	char	*val;

	msh->fd = 0;
	msh->one = 1;
	msh->zero = 0;
	msh->len = 0;
	msh->quote = 0;
	msh->cntPipes = 0;
	msh->countTokens = 0;
	msh->envp = envp;
	msh->export_list = NULL;
	msh->env_list = NULL;
	msh->c = (char)255;
	msh->envp_len = (int)ft_arrlen(envp);
	envInitEnvpList(msh);
	s1 = "HOME";
	val = ft_strjoin("/Users/", getValue(msh->export_list, "LOGNAME"));
	envUnset(msh, &s1);
	envAddVariable(msh, s1, val);
	free(val);
}
