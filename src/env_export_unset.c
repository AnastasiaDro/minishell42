//
// Created by Cesar Erebus on 6/17/21.
//
//#include "stdio.h"
#include <stddef.h>
#include "../libft/libft.h"
#include "minishell.h"
#define EXP_PREFIX "declare -x "

int ft_env(char **envp)
{
    int i;

    i = 0;
    while(envp[i])
    {
        write(1, envp[i], ft_strlen(envp[i]));
        write(1, "\n", 1);
        i++;
    }
    return (i);
}



int init_envp_list(char **arr, t_list **list)
{
		int index;
		char *str;
		int i;
		int j;
		int arr_len;
		char c = (char)255;

		arr_len = 0;
		while (arr[arr_len])
			arr_len++;

		j = 1;
		i = 1;
		str = arr[0];
		while (j< arr_len)
		{
			i = 0;
			while (i < arr_len) {
				if (arr[i] == NULL)
				{
					i++;
					continue;
				}
				else {
					if (ft_strncmp(arr[i], str, ft_strlen(arr[i])) <= 0)
					{
						str = arr[i];
						index = i;
					}
				}
				i++;
			}
			ft_lstadd_back(list, ft_lstnew(ft_strdup(str)));
			arr[index] = NULL;
			str = &c;
			j++;
		}
		return (arr_len);
    //вернем длину количества аргументов
}


void ft_print_export( t_msh *msh)
{
    t_list *vars;

    vars = msh->envp_list;

	while (vars)
	{
		printf("declare -x %s\n", (char *)vars->content);
		vars = vars->next;
	}
}