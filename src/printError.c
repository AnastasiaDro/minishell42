/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printError.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:21:33 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 23:05:13 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "minishell.h"

void	printError(char *command, int flag)
{
	char	*prefix;

	if (flag == 0)
	{
		prefix = ft_strjoin(NAME, command);
		perror(prefix);
		free(prefix);
		return ;
	}
	if (flag == 1)
	{
		errno = 127;
		write(2, command, ft_strlen(command));
		write(2, ": ", 2);
		write(2, COMMAND_ERR, ft_strlen(COMMAND_ERR));
		write(2, "\n", 1);
	}
}
