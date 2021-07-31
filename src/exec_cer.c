//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"
#include "env_export_unset.h"

int execCerBuiltin(t_msh *msh, char **comArr)
{
	int i;

	i = 0;
	if (!ft_strcmp(comArr[i], "echo"))
	{
		ft_echo(comArr);
		return (1);
	}
	if (!ft_strcmp(comArr[i], "pwd"))
	{
		ft_pwd();
		return (1);
	}
	if (!ft_strcmp(comArr[i], "env"))
	{
		ft_print_env(msh);
		printf("печатает лист\n");
		return (1);
	}
	if (!ft_strcmp(comArr[i],  "cd"))
	{
		ft_cd(msh, comArr[i + 1]);
		return (1);
	}
	if (!ft_strcmp(comArr[i], "export"))
	{
		if (comArr[i + 1] != NULL)
		{
			cerExportHandler(msh, comArr);
			return (1);
		}
		ft_print_export(msh);
		return (1);
	}
	if (!strcmp(comArr[i], "unset"))
	{
		if (comArr[i + 1] != NULL)
		{
			//сюда надо getFileNames
			i++;
			ft_unset(msh, &comArr[i]);
		}
		return (1);
	}
	return (0);
}

void cerExec(t_msh *msh) // не весьchar **fd
{
	int i;
	int j; //индекс для прохода по строке

	i = -1;
	int end;
	char **execArr;

	execArr = NULL;
	while (msh->cmd[++i])
	{
		t_cmd *cmd_s = malloc(sizeof (t_cmd));
		cmd_s->fileInFd = 0;
		cmd_s->fileOutFd = 1;
		cmd_s->com_num = i;
		cmd_s->cmdTokens = lexer_again(msh->cmd[i]); //засовываем в лексер команду
		//и получаем массив токенов команды
		j = 0;
		int arrLen = ft_arrlen(cmd_s->cmdTokens);
		while(j < arrLen) //пока у нас есть токены
		{
			//чекаем управляющие символы
			if (check_ctrl_symbol(cmd_s, &j))
			{
				j +=1;
				//printf("fileOutFd = %d\n", cmd_s->fileOutFd);
			}
			if (j >= arrLen)
				break;
			end = j;
			//беру массив команды с аргументами
			while (cmd_s->cmdTokens[end] && ft_strcmp(cmd_s->cmdTokens[end], ">>") && ft_strcmp(cmd_s->cmdTokens[end], ">") &&
			ft_strcmp(cmd_s->cmdTokens[end], "<") && ft_strcmp(cmd_s->cmdTokens[end], "<<"))
			{
				end++;
			}
			execArr = malloc(sizeof (char *) * (end - j + 1));
			execArr[end - j] = NULL;
			int u = 0;
			while(u < (end - j))
			{
				execArr[u] = ft_strdup(cmd_s->cmdTokens[u + j]);
				u++;
			}
			j = end;
		}
		int savestdout = dup(1);
		int savesrdin = dup(0);
//		dup2(cmd_s->fileInFd, STDIN_FILENO);
//		dup2(cmd_s->fileOutFd, STDOUT_FILENO);
		if (cmd_s->fileInFd != 0)
		{
			dup2(cmd_s->fileInFd, STDIN_FILENO);
			close(cmd_s->fileInFd);
		}
		if (cmd_s->fileOutFd != 1)
		{
			dup2(cmd_s->fileOutFd, STDOUT_FILENO);
			close(cmd_s->fileOutFd);
		}
		if (execArr != NULL)
		{
			if(!execCerBuiltin(msh, execArr))
				execBinary(msh, execArr, cmd_s);
		}
		dup2(savestdout, STDOUT_FILENO);
		dup2(savesrdin, STDIN_FILENO);
		if (cmd_s->here_doc)
			unlink("tmpFile");
		free(cmd_s);
	}
	waitChildren();
}