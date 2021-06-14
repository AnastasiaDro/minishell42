#include "minishell.h"

/*
	'' - 
	"$" - 
	$ - 
	| - 
	> -
	< -
	>> -
	<< - 
*/

void ft_parser(t_msh *msh)
{
	int i = -1;
	while (msh->line[++i])
	{
		if ((msh->line[i]) == '\'')
		{
			if (!msh->quote)
				msh->quote = 1;
			else if (msh->quote == 1)
				msh->quote = 0;
		}
		else if ((msh->line[i]) == '"')
		{
			if (!msh->quote)
				msh->quote = 2;
			else if (msh->quote == 2)
				msh->quote = 0;
		}
	}
	printf("msh->squote: |%d|\n", msh->quote);
	if (msh->quote == 1 || msh->quote == 2)
	{
		ft_error(1, "NOT_INTERPRETED_UNCOVERED_QOUTATION_MARKS");
		msh->quote = 0;
	}
	printf("after msh->line: %s\n", msh->line);
}
