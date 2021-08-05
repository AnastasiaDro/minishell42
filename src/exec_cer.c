/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:28:18 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 13:41:35 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execEcho(t_msh *msh, char **comArr)
{
	if (comArr[1] && !ft_strncmp(comArr[1], "$", 1) && (ft_strlen(comArr[1]) > 1))
		dollarSign(msh, comArr[1]);
	else
		ft_echo(comArr, 0);
	return (1);
}

int	execCerBuiltin(t_msh *msh, char **comArr)
{
	if (!ft_strcmp(comArr[0], "echo"))
		return (execEcho(msh, comArr));
	if (!ft_strncmp(comArr[0], "$", 1) && (ft_strlen(comArr[0]) > 1))
		return (dollarSign(msh, comArr[0]));
	if (!ft_strcmp(comArr[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(comArr[0], "cd"))
		return (ft_cd(msh, comArr[1]));
	if (!ft_strcmp(comArr[0], "env"))
		return (ft_print_env(msh));
	if (!ft_strcmp(comArr[0], "export"))
	{
		if (comArr[1] != NULL)
			return (cerExportHandler(msh, comArr));
		return (ft_print_export(msh));
	}
	if (!ft_strcmp(comArr[0], "unset"))
	{
		if (comArr[1] != NULL)
			envUnset(msh, &comArr[1]);
		return (1);
	}
	return (0);
}

void	cerExec(t_msh *msh)
{
	int i;
	int j;
	int end;
	char **execArr;
	i = -1;
	int zero = 0;
	int one = 1;

	execArr = NULL;
	//получили массив файловых дескрипторвж
	initFds(msh); //теперь подумать надо, как подключить к этому все остальное

	while (msh->cmd[++i])
	{
		t_cmd *cmd_s = malloc(sizeof(t_cmd));
		cmd_s->fileInFd = &zero;
		cmd_s->fileOutFd = &one;
		cmd_s->com_num = i;
		cmd_s->cmdTokens = lexer(msh->cmd[i]); //засовываем в лексер команду
		//и получаем массив токенов команды
		//cmd_s->cmdTokens = lexer_again(msh->cmd[i]);
		int y = 0;
		while (cmd_s->cmdTokens[y])
		{
			if (cmd_s->cmdTokens[y][0] == '$')
			{
				char *tmp;
				char *p;
				p = NULL;
				tmp = cmd_s->cmdTokens[y];
				p = (char *)getValue(msh->export_list, &cmd_s->cmdTokens[y][1]);
				if (p != NULL)
				{
					cmd_s->cmdTokens[y] = ft_strdup(p);
					free(tmp);
				}
				else if (cmd_s->cmdTokens[y][1] != '?')
				{
					cmd_s->cmdTokens[y] = NULL;
					free(tmp);
				}
			}
			y++;
		}

		if (i != 0)
			cmd_s->fileInFd = &(msh->fd[i][0]);
		if (i != msh->commands_num - 1)
			cmd_s->fileOutFd = &(msh->fd[i + 1][1]);
		j = 0;
		int arrLen = ft_arrlen(cmd_s->cmdTokens);
		if (!cmd_s->cmdTokens[0])
			return;
		while (j < arrLen) //пока у нас есть токены
		{
			//чекаем управляющие символы
			while (cmd_s->cmdTokens[j] && check_ctrl_symbol(cmd_s, &j))
				j += 1;
			end = j;
			//			//беру массив команды с аргументами
			while (cmd_s->cmdTokens[end] && ft_strcmp(cmd_s->cmdTokens[end], ">>") && ft_strcmp(cmd_s->cmdTokens[end], ">") &&
				   ft_strcmp(cmd_s->cmdTokens[end], "<") && ft_strcmp(cmd_s->cmdTokens[end], "<<"))
			{
				end++;
			}
			execArr = ft_calloc(sizeof(char *), (end - j + 1));
			int u = 0;
			while (u < (end - j))
			{
				execArr[u] = ft_strdup(cmd_s->cmdTokens[u + j]);
				u++;
			}
			j = end;
			while (cmd_s->cmdTokens[j] && check_ctrl_symbol(cmd_s, &j))
			{
				j += 1;
			}
		}
		int savestdout = dup(1);
		int savesrdin = dup(0);
		if (*cmd_s->fileInFd != 0)
		{
			dup2(*cmd_s->fileInFd, STDIN_FILENO);
			close(*cmd_s->fileInFd);
		}
		if (*cmd_s->fileOutFd != 1)
		{
			dup2(*cmd_s->fileOutFd, STDOUT_FILENO);
			close(*cmd_s->fileOutFd);
		}
		if (execArr != NULL && execArr[0] != NULL)
		{
			if (!execCerBuiltin(msh, execArr))
				execBinary(msh, execArr);
		}
		dup2(savestdout, STDOUT_FILENO);
		dup2(savesrdin, STDIN_FILENO);
		ft_freeStringsArr(execArr);
		ft_freeStringsArr(cmd_s->cmdTokens);
		free(cmd_s);
	}
	closeAllFds(msh->fd, msh->commands_num);
	waitChildren();
	ft_freeStringsArr(msh->cmd);
	unlink("tmpFile");
}