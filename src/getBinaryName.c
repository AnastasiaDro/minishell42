/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getBinaryName.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:01:24 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 17:01:30 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*getBinaryName(char *command)
{
	char	*s;

	s = command;
	if (!ft_strncmp(s, "/bin/", 5))
	{
		command = ft_substr(&(s[5]), 0, ft_strlen(&(s[5])));
		free(s);
	}
	return (command);
}
