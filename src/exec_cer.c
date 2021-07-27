//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"
#include "env_export_unset.h"

int execCerBuiltin(t_msh *msh, char *com)
{
	int i;

	i = 0;

	if (!ft_strncmp(com, "echo", 4))
	{
		ft_echo(msh->cmd);
		return (1);
	}
	if (!ft_strncmp(com, "pwd", ft_strlen(msh->cmd[i])))
	{
		ft_pwd();
		return (1);
	}
	if (!ft_strncmp(com, "env", 3))
	{
		ft_print_env(msh);
		printf("печатает лист\n");
		return (1);
	}
	if (!ft_strncmp(com, "cd", 2))
	{
		ft_cd(msh, "cd ..");
		return (1);
	}
	if (!ft_strncmp(com, "export", 5))
	{
		if (msh->cmd[i + 1] != NULL)
		{
			exportHandler(msh, i);
		}
		ft_print_export(msh);
		return (1);
	}
	if (!strncmp(com, "unset", 5))
	{
		if (com+5 != NULL)
		{
			//сюда надо getFileNames

			ft_unset(msh, &(msh->cmd[i + 1]));
		}

		return (1);
	}
	return (0);
}

//void dollarSign(t_msh *msh)
//{
//	int i;
//	int errNo = 0; //TODO: временно добавил
//
//	i = 0;
//	if (!ft_strncmp(msh->cmd[i], "$", 1))
//	{
//		if (!ft_strncmp(msh->cmd[++i], "?", 1))
//		{
//			ft_putnbr_fd(errNo, 1);
//			ft_putendl_fd(": command not found", 1);
//		}
//	}
//}
//
//void exec(t_msh *msh)
//{
//	int i;
//
//	i = -1;
//	parse_command(msh, 0);
////    while (msh->cmd[++i])
////    {
////        dollarSign(msh);
////        execBuiltin(msh);
////    }
//}