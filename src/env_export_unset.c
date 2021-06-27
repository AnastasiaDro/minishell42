//
// Created by Cesar Erebus on 6/17/21.
//
//#include "stdio.h"
#include <stddef.h>
#include "../libft/libft.h"
#include "minishell.h"
#define EXP_PREFIX "declare -x "
#include "env_list.h"

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


char **copy_arr(char **arr, int arr_len)
{
	char **copy;
	int i;

	i = 0;
	arr_len = ft_arrlen(arr);
	copy = ft_calloc(arr_len + 1, sizeof(char *));
	while (i < arr_len)
	{
		copy[i] = arr[i];
		i++;
	}
	return (copy);
	
}




int init_envp_list(char **arr, t_en_list **list)
{
		int index;
		char *str;
		int i;
		int j;
		int arr_len;
		char c = (char)255;
		char **arr_copy;


		arr_len = ft_arrlen(arr);
		arr_copy = copy_arr(arr, arr_len);
		j = 1;
		str = arr_copy[0];
		while (j< arr_len)
		{
			i = 0;
			while (i < arr_len) {
				if (arr_copy[i] == NULL)
				{
					i++;
					continue;
				}
				else {
					if (ft_strncmp(arr_copy[i], str, ft_strlen(arr_copy[i])) <= 0)
					{
						str = arr_copy[i];
						index = i;
					}
				}
				i++;
			}
			if (str != NULL)
				env_lstadd_back(list, env_lstnew(str));
			arr_copy[index] = NULL;
			str = &c;
			j++;
		}
		free(arr_copy);
		return (arr_len);
    //вернем длину количества аргументов
}


void ft_print_export( t_msh *msh)
{
    t_en_list *vars;
    char *name;
	char *value;

    vars = msh->envp_list;
	while (vars)
	{
		name = vars->name;
		value = vars->value;
		if (value != NULL)
			printf("declare -x %s=%s\n", vars->name, vars->value);
		else
		{
			if (vars->name)
			{
				printf("declare -x %s\n", vars->name);
			}
		}
		vars = vars->next;
	}
}



// //узнать, есть ли такая переменная
// int is_var_created(t_msh *msh, char *var)
// {
	
// }


// void ft_add_envvar(t_msh *msh, char *str)
// {
	
// 	//узнать, есть ли уже такая переменная
// 		//если да - изменить значение
// 		//если нет - добавить ее в export лист
	

// }
