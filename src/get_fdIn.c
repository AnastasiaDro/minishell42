//
// Created by Cesar Erebus on 7/27/21.
//
#include <sys/file.h>
#include "utils/msh_utils.h"
#include "../libft/libft.h"

int get_fdIn(char  *str, int *i, int o_flag)
{
	int end;
	char *fileName;
	int fileFd;


	move_index(str, i, ' '); //сдвинули индекс на первое слово
	end = *i;
	while (str[end] && str[end] != ' ')
		end++;
	str[end] = '\0';
	fileName = ft_strdup(&str[*i]);
	str[end] = ' ';
	*i = end;
	if (o_flag == 1)
		return (open(fileName,  O_CREAT | O_RDWR, 0644));
	return (open(fileName, o_flag));
}