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
	t_list *token = NULL;
	char **cmd;
	while (line && *line)
	{
		while (*line == ' ') // пропускаю пробелы в начале
			line++;
		ft_lstadd_back(&token, ft_lstnew(lexer(msh, &line))); // lexer->token->newList->ListAddBack
	}
	cmd = (char **)malloc(sizeof(char *) * (ft_lstsize(token) + 1));
	if (!cmd)
		exit(2);
	int k = -1;
	while (token)
	{
		cmd[++k] = strdup(token->content);
		token = token->next;
	}
	k = 0;
	if (!strncmp(cmd[k], "echo", 4))
	{
		ft_echo(cmd);
	}
	else if (!strncmp(cmd[k], "pwd", ft_strlen(cmd[k])))
	{
		ft_pwd();
	}
	else if (!strncmp(cmd[k], "cd", 3))
	{
		printf("k: %s\n", ft_strjoin(cmd[0], cmd[1]));
		ft_pwd("cd ..");
	}
}
