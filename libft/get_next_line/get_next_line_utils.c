/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:19:53 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 22:59:02 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gstrjoin(char *s1, char *s2)
{
	char	*newstr;
	size_t	new_s_flen;

	if (!s1 || !s2)
		return (NULL);
	new_s_flen = ft_strlen(s1) + ft_strlen(s2);
	newstr = malloc(sizeof(char) * (new_s_flen + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(&newstr[ft_strlen(s1)], s2, ft_strlen(s2) + 1);
	return (newstr);
}