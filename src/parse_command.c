//
// Created by Cesar Erebus on 7/27/21.
//
#include <sys/file.h>
#include "minishell.h"

#define RED_SMALL 1
#define RED_LARG 2
#define DOUBLE_LARG 3
#define HERE_DOC	4


int checkSymbol(char *cmd_str, int *i)
{
	if (cmd_str[(*i)] == '<')
	{
		if (cmd_str[(*i) + 1] == '<')
		{
			(*i)++;
			return (HERE_DOC);
		}
		else
			return (RED_SMALL);
	}
	if (cmd_str[(*i)] == '>')
	{
		if (cmd_str[(*i) + 1] == '>')
		{
			(*i)++;
			return (DOUBLE_LARG);
		}
		else
			return (RED_LARG);
	}
	return (0);
}

int parse_command(char *cmd_str)
{
	int i;
	int is_symbol;
	int end;

	t_command cmd;
	cmd.fileIn = 0;
	i = 0;
	while(cmd_str[i] && cmd_str[i] == ' ')
		i++;
	is_symbol = checkSymbol(cmd_str, &i);
	i++; //сдвинули указатель




	//если символ управляющий найден

	while(cmd_str[i] && cmd_str[i] == ' ')
			i++;
	if (checkSymbol(cmd_str, &i))
	{
		printf("%s %s '")
		return (258);
	}
}