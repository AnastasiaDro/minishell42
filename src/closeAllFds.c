/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closeAllFds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:05:30 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 17:05:31 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	closeAllFds(int **fd, int commands_num)
{
	int	i;
	int	**tmp;

	i = 0;
	tmp = fd;
	while (i < commands_num)
	{
		close(tmp[i][0]);
		close(tmp[i][1]);
		free(tmp[i]);
		tmp[i] = NULL;
		i++;
	}
	free(fd);
	fd = NULL;
}
