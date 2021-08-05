/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 16:19:57 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/05 16:19:58 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSH_UTILS_H
# define MSH_UTILS_H
# include "../minishell.h"

void	move_index(char *str, int *i, char c);
void	ft_lstFree(t_list *list);
void	ft_freeEnList(t_en_list *list);
int		ft_freeStringsArr(char **stringsArr);

#endif
