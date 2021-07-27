//
// Created by Cesar Erebus on 7/27/21.
//

#define RED_SMALL 1
#define RED_LARG 2
#define DOUBLE_LARG 3
#define HERE_DOC	4

#include "minishell.h"

int check_ctrl_symbol(char *cmd_str, int *i);
int parse_command(t_msh *msh, int com_num);

int main()
{
	t_command	command;
	char		**pathList;	//массив папок path
	int			i;			//индекс для прохода по строке

	i = 0;
	char *cmd_str;

	cmd_str = ft_strdup("> file99");
	check_ctrl_symbol(cmd_str, &i);

}