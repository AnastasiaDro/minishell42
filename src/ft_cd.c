/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:28:34 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/04 19:38:30 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	setPwd(t_msh *msh, char *dir)
{
	char		*newDir;
	t_en_list	*tEnL;
	t_en_list	*tExL;

	newDir = getcwd(NULL, 0);
	tEnL = msh->env_list;
	tExL = msh->export_list;
	while (tExL && tEnL)
	{
		if (!ft_strncmp(tExL->name, "OLDPWD", ft_strlen(tExL->name)))
			tExL->value = dir;
		else if (!ft_strncmp(tExL->name, "PWD", ft_strlen(tExL->name)))
			tExL->value = newDir;
		if (!ft_strncmp(tEnL->name, "OLDPWD", ft_strlen(tEnL->name)))
			tEnL->value = dir;
		else if (!ft_strncmp(tEnL->name, "PWD", ft_strlen(tEnL->name)))
			tEnL->value = newDir;
		tExL = tExL->next;
		tEnL = tEnL->next;
	}
}

int	ft_cd(t_msh *msh, const char *path)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	if (path == NULL)
		path = getValue(msh->export_list, "HOME");
	if (path != NULL)
	{
		if (chdir(path) == 0)
			setPwd(msh, dir);
		else
			printf("msh: cd: %s: No such file or directory\n", path);
	}
	else
		printf("msh: cd: HOME not set\n");
	return (1);
}
