
#include <stddef.h>
#include "../../libft/libft.h"
#include "../minishell.h"
#define EXP_PREFIX "declare -x "
#include "envList.h"

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

    p = getExportVar(&msh->export_list, name);
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
    	p = getExportVar(&msh->env_list, name);
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
