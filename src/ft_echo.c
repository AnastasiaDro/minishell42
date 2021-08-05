/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:41:07 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 18:14:41 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execEcho(t_msh *msh, char **comArr)
{
	int	len;

	len = ft_strlen(comArr[1]);
	if (comArr[1] && !ft_strncmp(comArr[1], "$", 1) && (len > 1))
		dollarSign(msh, comArr[1]);
	else
		ft_echo(comArr, 0);
	return (1);
}

void	ft_echo(char **av, int nflag)
{
	int	i;

	while (*++av && !ft_strncmp(*av, "-n", 2))
	{
		i = 1;
		while ((*av)[i] == 'n')
			i++;
		if ((*av)[i] == '\0')
			nflag = 1;
		else
		{
			if (nflag != 1)
				nflag = 0;
			break ;
		}
	}
	while (*av)
	{
		write(STDOUT_FILENO, *av, strlen(*av));
		if (*++av)
			write(STDOUT_FILENO, " ", 1);
	}
	if (!nflag)
		write(STDOUT_FILENO, "\n", 1);
}
