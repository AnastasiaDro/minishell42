/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 23:25:04 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 14:03:08 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**getToken(t_list *lexerLst)
{
	int		i;
	int		lstSize;
	char	**tokenArr;
	t_list	*tmp;

	i = 0;
	tmp = lexerLst;
	lstSize = ft_lstsize(tmp);
	tokenArr = malloc(sizeof(char *) * lstSize + 1);
	if (!tokenArr)
	{
		printf("NULL");
		return (NULL);
	}
		
	tokenArr[lstSize] = NULL;
	while (tmp)
	{
		printf("tokenArr\n");
		tokenArr[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_lstFree(lexerLst);
	return (tokenArr);
}

char *inQuotes(char *s, int *start)
{
	char	sym;
	int		end;
	
	(*start)++;
	// start = 1;
	sym = s[*start];
	end = *start;
	while (s[end] && s[end] != sym)
		end++;
	*start = end + 1;
	// printf("st: %d\n", start);
	return (ft_substr(s, (*start - 1), end - (*start)));
}

char	**lexer(char *s)
{
	// int lst_size = 0;
	char	*s1;
	int		end;
	int		start;
	t_list	*lexerLst;

	start = 0;
	while (s[start])
	{
		move_index(s, &start, ' ');
	
		if (s[start] == '\"' || s[start] == '\'')
		{
			// start++;
			s1 = inQuotes(s, &start);
		}
		else
		{
			end = start;
			while (s[end] && s[end] != ' ')
				end++;
			s1 = ft_substr(s, start, end - start);
			start = end;
		}
		ft_lstadd_back(&lexerLst, ft_lstnew(s1));
	}
	t_list *tmppp = lexerLst;
	while (tmppp)
	{
		printf("lexerLst: %s\n", tmppp->content);
		tmppp = tmppp->next;
	}
	
	return (getToken(lexerLst));
	// t_list *tmp = lexerLst;
	// lst_size = ft_lstsize(tmp);
	// char **arr = malloc(sizeof(char *) * lst_size + 1);
	// arr[lst_size] = NULL;

	// int i = 0;
	// tmp = lexerLst;
	// while (tmp)
	// {
	// 	arr[i] = ft_strdup(tmp->content);
	// 	tmp = tmp->next;
	// 	i++;
	// }
	// ft_lstFree(lexerLst);
	// return (arr);
}
