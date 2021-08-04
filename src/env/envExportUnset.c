
#include <stddef.h>
#include "../../libft/libft.h"
#include "../minishell.h"
#define EXP_PREFIX "declare -x "
#include "envList.h"

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


		arr_len = (int)ft_arrlen(arr);
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


t_en_list *ft_search_var(t_en_list *list, char *name)
{
    t_en_list *tmp;

    tmp = list;
    while (tmp)
    {
        if (!ft_strcmp(tmp->name, name))
            return (tmp);
        tmp = tmp->next;
    }

    return (NULL);
}

void ft_insert_to_list(t_en_list *prev, t_en_list *fol, t_en_list *new)
{
    prev->next = new;
    new->next = fol;
}

void    ft_export_add_new(t_en_list *export_list, char *name, char *value)
{
    t_en_list *tmp;
    t_en_list *previous;

    previous = export_list;
    tmp = export_list->next;

    if (ft_strncmp(previous->name, name, ft_strlen(name)) >= 0) //если наше имя меньше первого элемента то добавляем в начало
    {
        env_lstadd_front(&export_list, envParsedLstNew(name, value));
        return;
    }
    while(tmp)
    {
        if (ft_strncmp(tmp->name, name, ft_strlen(name)) > 0)
        {
            ft_insert_to_list(previous, tmp, envParsedLstNew(name, value));
            return;
        }
        previous = tmp;
        tmp = tmp->next;
    }
    env_lstadd_back(&export_list, envParsedLstNew(name, value));
}

//проверить, есть ли у новой переменной значение
t_en_list *ft_add_export_list(t_msh *msh, char *name, char *value)
{
    t_en_list *p;

    p = ft_search_var(msh->export_list, name);
    if (p)
	{
		p->value = value;
	}
    else
		ft_export_add_new(msh->export_list, name, value);
    return (p); // возвращаем указатель на элемент списка, в котором хранится наша переменная
}

// если флаг = true, то мы ищем переменную для замены ее значения. Если нет - то просто добавляем
void ft_add_env_list(t_msh *msh, char *name, char *value, t_en_list *flag)
{
    t_en_list *p;

    if(!flag)
        env_lstadd_back(&(msh->env_list), envParsedLstNew(name, value));
    else
    {
        p = ft_search_var(msh->env_list, name);
        p->value = value;
    }
}

//добавить новую переменную
void ft_add_variable(t_msh *msh, char *name, char *value)
{
   t_en_list *flag;

    flag = ft_add_export_list(msh, name, value);
    ft_add_env_list(msh, name, value, flag);
}

void delete_var(t_en_list *del, t_en_list *prev)
{
    prev->next = del->next;
    free(del->name);
    free(del->value);
    free(del);
    del = NULL;
}

void deleteInList(t_en_list **list, char **names)
{
    int i;
    t_en_list *prev;
    t_en_list *tmp;

    tmp = *list;
    prev = NULL;
    i = 0;

    while (names[i])
    {
        tmp = *list;
        while(tmp)
        {
            if (!ft_strcmp(names[i], tmp->name))
           {
                printf("СОВПАЛО! %s\n", tmp->name);
                if (prev)
                {
                    delete_var(tmp, prev);
                    break;
                }
                else
                {
                    *list = (*list)->next;
                    break;
                }
            }
            prev = tmp;
            tmp = tmp->next;
        }
        i++;
    }
}


void ft_unset(t_msh *msh, char **names)
{
    t_en_list *envTmp;
    t_en_list *expTmp;

    envTmp = msh->env_list;
    expTmp = msh->export_list;
    deleteInList(&envTmp, names);
    deleteInList(&expTmp, names);
}
