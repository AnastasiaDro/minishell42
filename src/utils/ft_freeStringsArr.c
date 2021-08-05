/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freeStringsArr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:19:45 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:19:46 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_freeStringsArr(char **stringsArr)
{
	int	i;

	i = 0;
	while (stringsArr[i])
	{
		free(stringsArr[i]);
		stringsArr[i] = NULL;
		i++;
	}
	free(stringsArr);
	stringsArr = NULL;
	return (0);
}
