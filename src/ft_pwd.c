/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 12:42:12 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/03 22:06:01 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(void)
{
	char	*dir;

	dir = getcwd(NULL, 0);
	printf("%s\n", dir);
	return (1);
}
