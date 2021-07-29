//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"

//void *setCommandFromStr(char *cmd_str, int *i, t_cmd *command)
//{
////	int end;
////	int tmp_fd;
////
////	end = *i;
////	while (cmd_str[end] && cmd_str[end] != '<' && cmd_str[end] != '>')
////		end++;
////	cmd_str[end] = '\0';
////	command->command = ft_strdup(&cmd_str[*i]);
////	*i = ++end;
////	if (cmd_str[*i] == '<')
////	{
////		command->here_doc = 1; //установили флаг, что есть here_doc
////		i++; 	//сдвинулись на LIMITER
////		//получить limiter
////		move_index(cmd_str, i, ' ');
////		end = *i;
////		while (cmd_str[end] && cmd_str[end] != '<' && cmd_str[end] != '>')
////			end++;
////		cmd_str[end] = '\0';
////		command->hLimiter = ft_strdup(&cmd_str[*i]); //получили лимитер, если нужно
////		command->fdOut = getTmpFile(command->hLimiter);
////		dup2(command->fdOut, STDOUT_FILENO);
////		//перевели стдоут на тмп файл
////		close(command->fdOut);
//	//}
//
//}