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

int init_envp_list(char **arr, t_en_list **list, t_en_list **env_list)
{
		int index;
		char *str;
		int i;
		int j;
		int arr_len;
		char c = (char)255;
//		char **arr_copy;
		
		arr_len = (int)ft_arrlen(arr);
	//	arr_copy = copy_arr(arr, arr_len);
		j = 1;
		i = 0;

		while(i < arr_len)
        {
            if (!strncmp(arr[i], "OLDPWD", 6))
                arr[i] = "OLDPWD";

            env_lstadd_back(env_list, env_lstnew(arr[i]));
		    i++;
        }
	    str = arr[0];
		while (j < arr_len)
		{
			i = 0;
			while (i < arr_len)
			{
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
			if (str != NULL)
            {
                env_lstadd_back(list, env_lstnew(str));
            }
            arr[index] = NULL;
			str = &c;
			j++;
		}
		return (arr_len);
    //вернем длину количества аргументов
}


void ft_print_export( t_msh *msh)
{
    t_en_list *vars;
	char *value;

    vars = msh->export_list;
	while (vars)
	{
		value = vars->value;
		if (value != NULL)
			printf("declare -x %s=\"%s\"\n", vars->name, vars->value);
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

void ft_print_env(t_msh *msh)
{
    t_en_list   *vars;
    char        *value;

    vars = msh->env_list;
    while (vars)
    {
        value = vars->value;
        if (value != NULL)
            printf("%s=\"%s\"\n", vars->name, vars->value);
        vars = vars->next;
    }
}

//проверить, есть ли у новой переменной значение
void ft_add_envarr(t_msh *t_msh, t_en_list *list)
{
	write(1, "HERE add envvar!\n", ft_strlen("HERE add envvar!\n"));
	char **new_arr;
	int arr_len;
	int i;
	int j;
	char **tmp;

	if (list->value == NULL)
		return;
	i = 0;
	j = 0;
	arr_len = ft_arrlen(t_msh->envp_arr);
	new_arr = malloc((arr_len + 2) * sizeof(char *));
	tmp = t_msh->envp_arr;
	write(1, "2HERE add envvar!\n", ft_strlen("2HERE add envvar!\n"));
	new_arr[arr_len + 1] = NULL;
	write(1, "3HERE add envvar!\n", ft_strlen("3HERE add envvar!\n"));
	while (t_msh->envp_arr[i])
	{
		new_arr[i] = t_msh->envp_arr[i];
		new_arr[i] = malloc((ft_strlen(list->name) + ft_strlen(list->value) + 2)*sizeof(char));
	new_arr[i][ft_strlen(list->name) + ft_strlen(list->value) + 2] = '\0';
		i++;
	}
	
	// new_arr[i] = malloc((ft_strlen(list->name) + ft_strlen(list->value) + 2)*sizeof(char));
	// new_arr[i][ft_strlen(list->name) + ft_strlen(list->value) + 2] = '\0';
	write(1, "4HERE add envvar!\n", ft_strlen("4HERE add envvar!\n"));
	////TODO
	i = 0;
	while (new_arr[i][j])
	{
		write(1, "0HERE add envvar!\n", ft_strlen("0HERE add envvar!\n"));
		//new_arr[i][j] = *(list->name);
		new_arr[i][j] = 'u';
		j++;
		list->name++;
		printf("%s\n", list->name);
		write(1, "5HERE add envvar!\n", ft_strlen("5HERE add envvar!\n"));
	}
	write(1, "51HERE add envvar!\n", ft_strlen("51HERE add envvar!\n"));
	new_arr[i][j] = '=';
	while (list->value)
	{
		new_arr[i][j] = *(list->value);
		j++;
		list->value++;
	}
	
	t_msh->envp_arr = new_arr;
	free(tmp);
}

//добавить новую переменную
void ft_add_envlist(t_msh *msh, char *str)
{
	//создаем и заполняем новый элемент списка
	write(1, "HERE add_anvlist!\n", ft_strlen("HERE add_anvlist!\n"));
	t_en_list *tmp;
	t_en_list *new_list;
	t_en_list *previous;
	
	tmp = msh->export_list;
	write(1, "2HERE add_anvlist!\n", ft_strlen("2HERE add_anvlist!\n"));
	new_list = env_lstnew(str);
	write(1, "3HERE add_anvlist!\n", ft_strlen("3HERE add_anvlist!\n"));
	previous = NULL;

	write(1, "31HERE add_anvlist!\n", ft_strlen("31HERE add_anvlist!\n"));
	//теперь его нужно вставить в текущий список, не нарушая алфавитный порядок
	while (tmp)
	{
		write(1, "40HERE add_anvlist!\n", ft_strlen("40HERE add_anvlist!\n"));
		printf("tmp->name %s\n", tmp->name);
		if (tmp->name != NULL && ft_strncmp(tmp->name, str, ft_strlen(tmp->name)) < 0)
		{
			if (!previous)
			{
				env_lstadd_front(&(msh->export_list), new_list);
				ft_add_envarr(msh, new_list);
				write(1, "4HERE add_anvlist!\n", ft_strlen("4HERE add_anvlist!\n"));
				return;
			}	
			else
			{
				write(1, "5HERE add_anvlist!\n", ft_strlen("5HERE add_anvlist!\n"));
				previous->next = new_list;
				new_list->next = tmp;
				ft_add_envarr(msh, new_list);
				return;
			}
		}
		tmp = tmp->next;
		
	}
	env_lstadd_back(&(msh->export_list), new_list);
	ft_add_envarr(msh, new_list);
}
