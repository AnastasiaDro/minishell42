#include "minishell.h"
#include "env_export_unset.h"

void	execBuiltin(t_msh *msh)
{
	int	i;

	i = 0;
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
    else if (!ft_strncmp(msh->cmd[i], "export", 6))
    {
        ft_print_export(msh);
    }
}

void	exec(t_msh *msh)
{
	execBuiltin(msh);
}