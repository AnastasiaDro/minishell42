/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 21:28:18 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 18:14:19 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	runExecArr(t_msh *msh, char **execArr)
{
	if (execArr != NULL && execArr[0] != NULL)
	{
		if (!execCerBuiltin(msh, execArr))
			execBinary(msh, execArr);
	}
}

void	run(t_msh *msh, t_cmd *cmd_s, int i)
{
	int		saveStdIn;
	int		saveStdOut;
	char	**execArr;

	if (i != 0)
		cmd_s->fileInFd = &(msh->fd[i][0]);
	if (i != msh->commands_num - 1)
		cmd_s->fileOutFd = &(msh->fd[i + 1][1]);
	saveStdIn = dup(0);
	saveStdOut = dup(1);
	execArr = hasTokens(cmd_s);
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
	runExecArr(msh, execArr);
	dup2(saveStdOut, STDOUT_FILENO);
	dup2(saveStdIn, STDIN_FILENO);
	ft_freeStringsArr(execArr);
}

void	replace(t_msh *msh, t_cmd *cmd_s, int y)
{
	char	*p;
	char	*tmp;

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

void	cerExec(t_msh *msh)
{
	int		i;
	int		y;
	t_cmd	*cmd_s;

	i = -1;
	initFds(msh);
	while (msh->cmd[++i])
	{
		cmd_s = malloc(sizeof(t_cmd));
		cmd_s->fileInFd = &msh->zero;
		cmd_s->fileOutFd = &msh->one;
		cmd_s->com_num = i;
		cmd_s->cmdTokens = lexer(msh->cmd[i]);
		y = -1;
		while (cmd_s->cmdTokens[++y])
			if (cmd_s->cmdTokens[y][0] == '$')
				replace(msh, cmd_s, y);
		run(msh, cmd_s, i);
		ft_freeStringsArr(cmd_s->cmdTokens);
		free(cmd_s);
	}
	closeAllFds(msh->fd, msh->commands_num);
	waitChildren();
	ft_freeStringsArr(msh->cmd);
	unlink("tmpFile");
}
