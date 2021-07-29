//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"
#include "env_export_unset.h"

int execCerBuiltin(t_msh *msh, t_cmd *cmd_s, int *j)
{
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "echo"))
	{
		ft_echo(&cmd_s->cmdTokens[*j]);
		return (1);
	}
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "pwd"))
	{
		ft_pwd();
		return (1);
	}
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "env"))
	{
		ft_print_env(msh);
		printf("печатает лист\n");
		return (1);
	}
	if (!ft_strcmp(cmd_s->cmdTokens[*j],  "cd"))
	{
		ft_cd(msh, "cd ..");
		return (1);
	}
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "export"))
	{
		if (cmd_s->cmdTokens[*j + 1] != NULL)
		{
			//exportHandler(msh, i);
			cerExportHandler(msh, cmd_s, j);
			return (1);
		}
		ft_print_export(msh);
		return (1);
	}
	if (!strcmp(cmd_s->cmdTokens[*j], "unset"))
	{
		if (cmd_s->cmdTokens[*j + 1] != NULL)
		{
			//сюда надо getFileNames
			(*j)++;
			ft_unset(msh, &cmd_s->cmdTokens[*j]);
		}
		return (1);
	}
	return (0);
}

void cerExec(t_msh *msh)
{
	int i;
	int j; //индекс для прохода по строке
	char **cmdArr;

	i = -1;

	//parse_command(msh, 0);

	while (msh->cmd[++i])
	{
		t_cmd *cmd_s = malloc(sizeof (t_cmd));
		cmd_s->com_num = i;
		cmd_s->cmdTokens = lexer_again(msh->cmd[i]); //засовываем в лексер команду
		//и получаем массив токенов команды
		j = 0;
		while(cmd_s->cmdTokens[j]) //пока у нас есть токены
		{
			//чекаем управляющие символы
			check_ctrl_symbol(cmd_s, &j);
			//чекаем билдины
			execCerBuiltin(msh, cmd_s, &j);
			j++;
			//чекаем и/или выполняем бинарники
		}
		free(cmd_s);

	}
	waitChildren();
}