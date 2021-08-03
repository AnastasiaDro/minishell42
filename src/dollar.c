/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:13:31 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/03 20:49:54 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	dollarSign(t_msh *msh, char *dollar)
{
	char	*token;
	char	*found;

	token = ft_strsep(&dollar, " $");
	while (token != NULL)
	{
		if (ft_strlen(token) > 0)
		{
			if (*token == '?')
			{
				ft_putnbr_fd(errno, 2);
				ft_putendl_fd("", 2);
			}
			else
			{
				found = (char *)getValue(msh->export_list, token);
				printf("found: |%s|\n", found);
				if (found != NULL)
					printf("%s\n", found);
				else
					write(STDOUT_FILENO, "\n", 1);
			}
			token = ft_strsep(&dollar, " $");
		}
	}
}
