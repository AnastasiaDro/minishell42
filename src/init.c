#include "minishell.h"


int init_envp_list(t_list **envp_list, char **envp)
{
    int i;
    t_list *tmp_list;
    t_list *t;

    t = NULL;
    *envp_list = ft_lstnew(envp[0]);
    i = 1;
    t_list *lst_tmp = *envp_list;
    while(envp[i])
    {
        while(lst_tmp)
        {
            if (strcmp(envp[i], (lst_tmp->content)) < 0)
            {
                if (t == NULL)
                {
                    ft_lstadd_front(envp_list, ft_lstnew(envp[i]));
                    t = *envp_list;
                    tmp_list = t->next;
                    break;
                }
                else
                {
                    t->next = ft_lstnew(envp[i]);
                    t->next->next = tmp_list;
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
    return (i); //вернем длину количества аргументов
}

void	ft_init(t_msh *msh, char **envp)
{
	msh->fd = 0;
	msh->len = 0;
	msh->line = NULL;
	msh->quote = 0;
	//я добавила
	msh->envp_list = NULL;
	msh->envp_len = init_envp_list(&(msh->envp_list), envp);
}

