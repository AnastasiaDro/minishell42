#include "minishell.h"

// static void	setPwd(char *dirName)
// {
	
// }

static void setPwd(t_msh *msh)
{
    char *dir;
    // char buf[1024];

    dir = "jkeitha";
    t_en_list *tmp;

    tmp = msh->envp_list;
    while (tmp)
    {
        if (!strncmp(tmp->name, "PWD", 3)) // TODO: change strcmp to ft_strcmp
        {
            printf("currentValue: %s\n", tmp->value);
          //  free(msh->envp_list->value);
            printf("currentValue:1 %s\n", tmp->value);
            tmp->value = dir;
            printf("currentValue:3 %s\n", tmp->value);
        }
        tmp = tmp->next;
    }
}

void ft_cd(t_msh *msh, const char *path)
{
    setPwd(msh);
    path = "/Users/cerebus/projects/minishell42-2/src";

    chdir(path);
}
