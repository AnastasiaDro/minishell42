//
// Created by Cesar Erebus on 6/17/21.
//
//#include "stdio.h"
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



int init_envp_list(t_list **envp_list, char **envp)
{
    write(1, "N\n", 2);
    int i;
    t_list *tmp_list;
    t_list *t;

    t = NULL;
    *envp_list = ft_lstnew(envp[0]);
    printf("envp[i] = %s\n", envp[0]);
    i = 1;
    t_list *lst_tmp = *envp_list;
    while(envp[i])
    {
        printf("i = %d ", i);
        printf("envp[i] = %s\n", envp[i]);
        write(1, "2\n", 2);
        while(lst_tmp)
        {
            write(1, "3\n", 2);
            if (strcmp(envp[i], (lst_tmp->content)) < 0)
            {
                write(1, "4\n", 2);
                if (t == NULL)
                {
                    ft_lstadd_front(envp_list, ft_lstnew(envp[i]));
                    t = *envp_list;

                    tmp_list = t->next;
                    write(1, "5\n", 2);
                    break;
                }
                else
                {
                    t->next = ft_lstnew(envp[i]);
                    t->next->next = tmp_list;
                    write(1, "6\n", 2);
                    break;
                }
            }
            t = lst_tmp;
            lst_tmp = lst_tmp->next;
        }
        if (lst_tmp == NULL)
            t->next = ft_lstnew(envp[i]);
        else
            t = NULL;
        lst_tmp = *envp_list;
        i++;
    }
    write(1, "U\n", 2);
    return (i);
    //вернем длину количества аргументов
}


void insert_var(t_list **envp_list, char *var)
{
    t_list *lst_tmp;
    t_list *t;

    t = NULL;
    lst_tmp = *envp_list;
    while (lst_tmp) {
        if (strcmp(var, (lst_tmp->content)) < 0) {
            printf("envp[i] = %s < cont = %s\n\n", var, lst_tmp->content); // если новый аргумент меньше
            if (t == NULL) {
                ft_lstadd_front(envp_list, ft_lstnew(var));
                t = *envp_list;
                lst_tmp = t->next;
                break;
            } else {
                printf("lst_tmp->content %s\n", (char *) (lst_tmp->content));
                printf("t->content %s\n", (char *) (t->content));
                t->next = ft_lstnew(var);
                t->next->next = lst_tmp;
                break;
            }
        }
        t = lst_tmp;
        lst_tmp = lst_tmp->next;
    }
    if (lst_tmp == NULL)
        t->next = ft_lstnew(var);  //???
}


int ft_export(char **envp, t_msh *msh)
{
    int i;
    t_list *vars;

    vars = msh->envp_list;


    i = 0;
    while(envp[i])
    {
        insert_var(&vars, envp[i]);
        i++;
    }
    return (i);
}