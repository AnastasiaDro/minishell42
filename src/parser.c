#include "minishell.h"

void inQuotes(char **line)
{
	char sym;

	sym = **line;

	++*line;
	printf("sym: %c\n", **line);
	printf("++*line: %s\n", *line);
	while (*line && **line && **line != sym)
	{
		// if (*(*line + 1) == sym)
		// {
		// 	// ++*line;
		// 	printf("closedQuote: %c\n", **line);
		// }
		// else
		++*line;
	}
	if (**line == '\0')
		ft_error(1, "NOT_INTERPRETED_UNCOVERED_QOUTATION_MARKS");
	else
		++*line;
}

char *ft_lexer(char **line)
{
	char		*newToken;
	const char	*start = *line;
	printf("*line: %s\n", *line);
	printf("*start: %s\n", start);
	while (*line && **line && !ft_strchr(" >|<", **line))
	{
		if (**line == '\'' || **line == '\"')
			inQuotes(line);
		else
			++*line;
	}

	newToken = ft_substr(start, 0, *line - start);
	if (newToken == NULL)
		return (NULL);
	return (newToken);
}

void ft_parser(t_msh *msh, char *line)
{
	char *token;

	while (line && *line)
	{
		while (*line == ' ')
			line++;
		token = ft_lexer(&line);
		printf("token: |%s| len: |%d|\n", token, msh->len);
	}
}
