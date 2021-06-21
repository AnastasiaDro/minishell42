#include "minishell.h"

void ft_lexer(t_msh *msh, int j, int i)
{
	char *token = NULL;
	// int i = -1;
	// while (msh->line[++i])
	// {
	// if (msh->line[++i] == '\'' || msh->line[++i] == '\"')
	token = ft_substr(msh->line, j + 1, (i - j) - 1);
	printf("tokenLen: %zu\n", ft_strlen(token));
	printf("token:|%s|\n", token);
	// }
}

void ft_parser(t_msh *msh)
{
	int i = -1;
	int j = 0;
	int k = 0;
	char *tmp = NULL;
	while (msh->line[++i])
	{
		if (ft_isprint(msh->line[i]))
		{
			k = i;
			if ((msh->line[i]) == '\'')
			{
				if (!msh->quote)
				{
					msh->quote = 1;
					j = i;
				}
				else if (msh->quote == 1)
				{
					ft_lexer(msh, j, i);
					msh->quote = 0;
				}
			}
			else if ((msh->line[i]) == '"')
			{
				if (!msh->quote)
				{
					msh->quote = 2;
					j = i;
				}
				else if (msh->quote == 2)
				{
					ft_lexer(msh, j, i);
					msh->quote = 0;
				}
			}
		}
		else if (msh->line[i] == ' ')
		{
			tmp = ft_substr(msh->line, k, msh->len - i);
			printf("tmp: |%s|\n", tmp);
		}

		// else
		// 	i++;
	}
	// printf("tmp: |%s|\n", *tmp);
	printf("len: %d\n", msh->len);
	printf("j1: %d\n", j);
	printf("j: %d\n", msh->len - j);
	if (msh->quote == 1 || msh->quote == 2)
	{
		ft_error(1, "NOT_INTERPRETED_UNCOVERED_QOUTATION_MARKS");
		msh->quote = 0;
	}
	printf("after msh->line: %s\n", msh->line);
	// ft_lexer(msh);
}
