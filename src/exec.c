#include "minishell.h"
#include "env_export_unset.h"

void execBuiltin(t_msh *msh)
{
    int i;

    i = -1;
    while (msh->cmd[++i])
    {
        if (!ft_strncmp(msh->cmd[i], "echo", 4))
        {
            ft_echo(msh->cmd);
        }
        else if (!ft_strncmp(msh->cmd[i], "pwd", ft_strlen(msh->cmd[i])))
        {
            ft_pwd();
        }
        else if (!ft_strncmp(msh->cmd[i], "env", 3))
        {
            ft_print_env(msh);
            printf("печатает лист\n");
        }
        else if (!ft_strcmp(msh->cmd[i], "cd"))
        {
            ft_cd(msh, "cd ..");
        }
        else if (!ft_strcmp(msh->cmd[i], "export"))
        {
            if (msh->cmd[i + 1] != NULL)
            {
                exportHandler(msh, i);
            }
            ft_print_export(msh);
        }
        else if (!strncmp(msh->cmd[i], "unset", ft_strlen(msh->cmd[i])))
        {
            if (msh->cmd[i + 1] != NULL)
                ft_unset(msh, &(msh->cmd[i + 1]));
        }
    }
}

void dollarSign(t_msh *msh)
{
    int i;
    int errNo = 0; //TODO: временно добавил

    i = 0;
    if (!ft_strncmp(msh->cmd[i], "$", 1))
    {
        if (!ft_strncmp(msh->cmd[++i], "?", 1))
        {
            ft_putnbr_fd(errNo, 1);
            ft_putendl_fd(": command not found", 1);
        }
    }
}

void exec(t_msh *msh)
{
    dollarSign(msh);
    execBuiltin(msh);
}