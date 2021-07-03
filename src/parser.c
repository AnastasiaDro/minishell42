
#include "minishell.h"
#include "env_export_unset.h"

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
    start = *line; // запоминаю указатель на строку
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
    int list_size;

    while (line && *line)
    {
        while (*line == ' ') // пропускаю пробелы в начале
            line++;
        ft_lstadd_back(&token, ft_lstnew(lexer(msh, &line)));
    }
    list_size = ft_lstsize(token);
    cmd = (char **)malloc(sizeof(char *) * (list_size + 1));
  //  cmd[list_size] = NULL;
//    write(1, "TEST\n", 5);
//    while(cmd)
//    {
//        printf("cmd = %s\n", *cmd);
//        cmd++;
//    }

    if (!cmd)
        exit(2);
// хз почему раньше не занулить, но учли занулять до if(!cmd) - ругается

    cmd[list_size] = NULL;
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
    else if (!strncmp(cmd[k], "env", 3))
    {
        ft_print_env(msh);
    }
    else if (!strcmp(cmd[k], "cd"))
    {
        ft_cd(msh, "cd ..");
    }
    else if (!strncmp(cmd[k], "export", 6))
    {
        ft_print_export(msh);
    }
    else if (!strncmp(cmd[k], "unset", ft_strlen(cmd[k])))
    {
        if (cmd[k+1] != NULL)
            ft_unset(msh, &(cmd[k+1]));
    }
}