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

char	*inQuotes(char *s, int *start)
{
	char	sym;
	int		end;
	char	*token;

	sym = s[*start];
	(*start)++;
	end = *start;
	while (s[end] && s[end] != sym)
		end++;
	token = ft_substr(s, (*start), end - (*start));
	*start = end + 1;
	return (token);
}

t_list	*addLexLst(char *s)
{
	int		start;
	int		end;
	char	*s1;
	t_list	*lexLst;

	start = 0;
	lexLst = NULL;
	while (s[start])
	{
		move_index(s, &start, ' ');
		if (s[start] == '\"' || s[start] == '\'')
			s1 = inQuotes(s, &start);
		else
		{
			end = start;
			while (s[end] && s[end] != ' ')
				end++;
			s1 = ft_substr(s, start, end - start);
			start = end;
		}
		ft_lstadd_back(&lexLst, ft_lstnew(s1));
	}
	return (lexLst);
}

char	**lexer(char *s)
{
	t_list	*lexLst;
	int		lst_size;
	int		i;
	char	**arr;
	t_list	*tmp;

	lexLst = addLexLst(s);
	lst_size = ft_lstsize(lexLst);
	arr = malloc(sizeof(char *) * lst_size + 1);
	if (!arr)
		return (NULL);
	arr[lst_size] = NULL;
	i = 0;
	tmp = lexLst;
	while (tmp)
	{
		arr[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_lstFree(lexLst);
	return (arr);
}
