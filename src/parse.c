#include "minishell.h"

void	ft_parse(t_msh *msh, char str, int len)
{
	// char *line;
	printf("str: %c\n", str);
	printf("len: %d\n", msh->len);
	if (!msh->line)
	{
		msh->line = (char *)malloc(sizeof(char) * 2);
		msh->line[0] = str;
		msh->line[1] = '\0';
		msh->len = 1;
	}
	else
	{
		msh->len += len;
		msh->line = ft_realloc(msh->line, msh->len + 1);
		msh->line[msh->len - 1] = str;
		msh->line[msh->len] = '\0';
	}
}
