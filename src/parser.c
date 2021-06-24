#include "minishell.h"

void inQuotes(char **line)
{
	char sym;

	sym = **line; // запоминаю первый символ(" или ') строки

	++*line;								 // пропускаю первый символ(" или ') строки
	while (*line && **line && **line != sym) // пока не встречу закрывающую кавычку
		++*line;
	if (**line == '\0')							// если не нашел закрывающую кавычку и дошел до конца строки
		ft_error(1, "MULTILINE_NOT_SUPPORTED"); // вывожу сообщение
	else
		++*line;
}

char *lexer(t_msh *msh, char **line)
{
	char *start;
	char *newToken;
	(void)msh->fd; // просто чтобы unuse msh не было
	start = *line; // запоминаю указатель на страку
	if (!ft_strncmp(*line, ">>", 2) || !ft_strncmp(*line, "<<", 2))
		*line += 2;
	else if (**line == '>' || **line == '|' || **line == '<')
		++*line;
	else
	{
		while (*line && **line && !ft_strchr(" >|<", **line))
		{
			if (**line == '\'' || **line == '\"') // если встречаю кавычек(одинарные или двойные)
				inQuotes(line);
			else
				++*line;
		}
	}
	newToken = ft_substr(start, 0, *line - start);
	if (!newToken)
		return (NULL);
	return (newToken);
}

void parser(t_msh *msh, char *line)
{
	char *token;

	while (line && *line)
	{
		while (*line == ' ') // пропускаю пробелы в начале
			line++;
		token = lexer(msh, &line); // лексер возвращает токен
		printf("token: |%s| len: |%d|\n", token, msh->len);
	}
}
