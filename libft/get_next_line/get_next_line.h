/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 14:15:29 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 22:56:36 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <libc.h>
# include "../libft.h"

int		get_next_line(int fd, char **line);

int		ft_increase_tail(char **tail, char **buff, int *start, int read_bytes);

int		ft_split_n_tail(char *pn, char **tail, char **line);

int		ft_get_from_tail(char **line, char **tail);

int		m_read(int *read_bytes, int fd, char *buff);

char	*find_char(char **pn, char *s);

char	*ft_gstrjoin(char *s1, char *s2);

#endif
