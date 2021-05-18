#include "minishell.h"

void	ft_parse(t_msh *msh, char *str, int len)
{
	char *line;

	line = "";
	printf("str1: |%s|\n", str);
	line = ft_strjoin(line, str);

	printf("s: |%s|\n", str);
	printf("len: |%d|\n", len);
	
	// if (str[0 == "echo")
	// 	ft_echo(msh, str);
	msh->fd = 0;
}