/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envList.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:16:56 by cerebus           #+#    #+#             */
/*   Updated: 2021/08/03 13:36:11 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVLIST_H
# define ENVLIST_H
#include "../minishell.h"

typedef struct s_en_list
{
	char				*name;
	char				*value;
	struct s_en_list	*next;
}				t_en_list;

int			env_lstsize(t_en_list *lst);

t_en_list	*env_lstlast(t_en_list *lst);

void		env_lstadd_back(t_en_list **lst, t_en_list *new);

t_en_list	*env_lstnew(char *str);

void		env_lstadd_front(t_en_list **lst, t_en_list *new);

t_en_list	*envParsedLstNew(char *name, char *value);

void		envSetNameValue(t_en_list *list, char *str);

t_en_list	*envParsedLstNew(char *name, char *value);

void 		deleteInList(t_en_list **list, char **names);

#endif