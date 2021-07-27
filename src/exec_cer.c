//
// Created by Cesar Erebus on 7/27/21.
//


#include "../libft/libft.h"
#include "minishell.h"

void execBuiltin_cer(t_command *command)
{
	int i;

	i = 0;
	if (!ft_strncmp(command->command, "echo", 4))
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
//        if (msh->cmd[i + 1] != NULL)
//        {
//            //exportHandler(msh, i);
//        }
		ft_print_export(msh);
	}
	else if (!strncmp(msh->cmd[i], "unset", ft_strlen(msh->cmd[i])))
	{
		if (msh->cmd[i + 1] != NULL)
			ft_unset(msh, &(msh->cmd[i + 1]));
	}
}
