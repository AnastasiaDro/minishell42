/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envInitEnvpList.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:14:05 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 20:29:18 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	setOLDPWD(t_msh *msh)
{
	int	i;

	i = 0;
	while (i < msh->envp_len)
	{
		if (!ft_strncmp(msh->envp[i], "OLDPWD", 6))
			msh->envp[i] = "OLDPWD";
		env_lstadd_back(&msh->env_list, env_lstnew(msh->envp[i]));
		i++;
	}
}

void	is_less(t_msh *msh, int i, char **str, int *index)
{
	if (ft_strncmp(msh->envp[i], *str, ft_strlen(msh->envp[i])) <= 0)
	{
		*str = msh->envp[i];
		*index = i;
	}
}

void	envInitEnvpList(t_msh *msh)
{
	int		index;
	char	*str;
	int		i;
	int		j;

	j = 0;
	setOLDPWD(msh);
	str = msh->envp[0];
	while (++j < msh->envp_len)
	{
		i = -1;
		while (++i < msh->envp_len)
		{
			if (msh->envp[i] == NULL)
				continue ;
			else
				is_less(msh, i, &str, &index);
		}
		if (str != NULL)
			env_lstadd_back(&msh->export_list, env_lstnew(str));
		msh->envp[index] = NULL;
		str = &msh->c;
	}
}
