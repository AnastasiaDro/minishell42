#include "minishell.h"
#include "env_export_unset.h"

void inQuotes(char **line)
{
    char sym;

    sym = **line;
    ++*line;
    while (*line && **line && **line != sym)
        ++*line;
    if (**line == '\0')
        ft_error(1, "MULTILINE_NOT_SUPPORTED");
    else
        ++*line;
}

char *lexer(t_msh *msh, char **line)
{
    char *start;
    char *newToken;

    (void)msh->fd;
    start = *line;
    if (!ft_strncmp(*line, ">>", 2) || !ft_strncmp(*line, "<<", 2))
        *line += 2;
    else if (**line == '>' || **line == '|' || **line == '<')
        ++*line;
    else
    {
        while (*line && **line && !ft_strchr(" >|<", **line))
        {
            if (**line == '\'' || **line == '\"')
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
    int i;
    t_list *token;

    token = NULL;
    while (line && *line)
    {
        while (*line == ' ')
            line++;
        ft_lstadd_back(&token, ft_lstnew(lexer(msh, &line)));
    }
    msh->cmd = (char **)malloc(sizeof(char *) * (1 + ft_lstsize(token)));
    if (!msh->cmd)
    {
        printf("Error: malloc[msh->cmd]\n"); //TODO: Usage ft_exit();
        exit(2);
    }
    i = -1;
    while (token)
    {
        msh->cmd[++i] = ft_strdup(token->content);
        printf("currentToken: %s\n", token->content);
        token = token->next;
    }
    ft_lstclear(&token, free);
}