//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"
#include "env_export_unset.h"

int execCerBuiltin(t_msh *msh, t_cmd *cmd_s, int *j)
{
	void *func;

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

	i = -1;
	int end;

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
			if (check_ctrl_symbol(cmd_s, &j))
				j++;
			printf("j = %d\n", j);
			end = j;
	//		printf("cmd_s->cmdTokens[j] = %s\n", cmd_s->cmdTokens[j]);
			//беру массив команды с аргументами
			while (cmd_s->cmdTokens[end] && ft_strcmp(cmd_s->cmdTokens[end], ">>") && ft_strcmp(cmd_s->cmdTokens[end], ">") &&
			ft_strcmp(cmd_s->cmdTokens[end], "<") && ft_strcmp(cmd_s->cmdTokens[end], "<<"))
			{
				//printf("end = %d\n", end);
				end++;
			}

			printf("вышли\n");
			char **execArr = malloc(sizeof (char *) * (end - j + 1));
			printf("end - j = %d\n", end - j);
			execArr[end - j] = NULL;
			int u = 0;
			while(u < (end - j))
			{
				execArr[u] = ft_strdup(cmd_s->cmdTokens[u + j]);
				printf("execArr[u] = %s\n", execArr[u]);
				u++;
			}
			j = end;

		}


		free(cmd_s);

	}
	waitChildren();
}