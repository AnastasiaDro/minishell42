#include "minishell.h"

void singleQuotes(char **line)
{
	char *close_quote;

	++*line;
	close_quote = ft_strchr(*line, '\'');
	if (close_quote)
		*line = close_quote - 1;
	else
		ft_error(1, "NOT_INTERPRETED_UNCOVERED_QOUTATION_MARKS");
}

void inQuotes(char **line)
{
	// char sym;

	// sym = **line;
	++*line;
	while (*line && **line && **line != '\"')
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

	while (*line && **line && !ft_strchr(" >|<", **line))
	{
		if (**line == '\''){
			singleQuotes(line);
			break;
		}
		else if (**line == '\"')
		{
			printf("do line: |%s|\n", *line);
			inQuotes(line);
			printf("posle line: |%s|\n", *line);
		}
		else
			++*line;
	}
	// printf
	newToken = ft_substr(start + 1, 0, *line - start);
	if (newToken == NULL)
		return (NULL);
	return (newToken);
}