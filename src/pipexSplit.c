/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cerebus <cerebus@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 19:34:13 by cerebus           #+#    #+#             */
/*   Updated: 2020/11/26 12:25:20 by cerebus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../libft/libft.h"

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	words_num;

	i = 0;
	words_num = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			words_num++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (words_num);
}

static char	**ft_free(int arr_num, char **res)
{
	arr_num = arr_num - 1;
	while (arr_num >= 0)
	{
		free(res[arr_num]);
		arr_num--;
	}
	free(res);
	return (NULL);
}

static char	**ft_fill_res(char **res, char const *s, char c, int words_num)
{
	int	i;
	int	start;
	int	arr_num;
	int	s_len;

	i = 0;
	arr_num = 0;
	while (s[i] != '\0' && arr_num < words_num)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		s_len = i - 1 - start + 3;
		res[arr_num] = malloc((s_len) * sizeof(char));
		if (!(res[arr_num]))
			return (ft_free(arr_num, res));
		ft_memcpy(res[arr_num], &s[start], s_len - 1);
		res[arr_num][s_len - 1] = '\0';
		res[arr_num][s_len - 2] = '/';
		arr_num++;
	}
	res[arr_num] = NULL;
	return (res);
}

char	**pipexSplit(char const *s, char c)
{
	int		words_num;
	char	**res;

	if (!s)
		return (NULL);
	words_num = ft_count_words(s, c);
	res = (char **)malloc((words_num + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	return (ft_fill_res(res, s, c, words_num));
}
