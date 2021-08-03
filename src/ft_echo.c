/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:41:07 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/02 13:09:25 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
