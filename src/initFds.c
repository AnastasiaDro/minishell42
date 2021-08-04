/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initFds.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:20:37 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/04 23:20:39 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	initFds(t_msh *msh)
{
	int	i;

	i = 0;
	msh->fd = malloc(sizeof(int *) * msh->commands_num);
	while (i < msh->commands_num)
	{
		msh->fd[i] = malloc(sizeof(int) * 2);
		pipe(msh->fd[i]);
		i++;
	}
	return (i);
}
