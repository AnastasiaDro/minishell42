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
        i++;
    }
    return (i);
}

void insert_var(t_list **vars, char *new_content)
{
    char *current;
    char *next;
    t_list *var;

    var = *vars;
    while (var->next != NULL)
    {
        break;
    }
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