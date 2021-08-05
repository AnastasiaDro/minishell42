/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   waitChildren.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 17:08:02 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 17:08:03 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/wait.h>
#include <unistd.h>

void	waitChildren(void)
{
	while (1)
	{
		if (wait(NULL) == -1)
			break ;
	}
}
