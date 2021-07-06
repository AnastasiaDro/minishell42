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
    t_list *token = NULL;
 
    while (line && *line)
    {
        while (*line == ' ')
            line++;
        ft_lstadd_back(&token, ft_lstnew(lexer(msh, &line)));
    }
    // int lstsize = ft_lstsize(token);
    msh->cmd = (char **)malloc(sizeof(char *) * (1 + ft_lstsize(token)));
    if (!msh->cmd)
        exit(2);
    int k = -1;
    while (token)
    {
        msh->cmd[++k] = ft_strdup(token->content);
        printf("currentToken: %s\n", token->content);
        token = token->next;
    }
    printf("k: %s\n", msh->cmd[k + 1]);
    k = 0;
    if (!ft_strncmp(msh->cmd[k], "echo", 4))
    {
        ft_echo(msh->cmd);
    }
    else if (!ft_strncmp(msh->cmd[k], "pwd", ft_strlen(msh->cmd[k])))
    {
        ft_pwd();
    }
    else if (!ft_strncmp(msh->cmd[k], "env", 3))
    {
        ft_print_env(msh);
        printf("печатает лист\n");
    }
    else if (!ft_strcmp(msh->cmd[k], "cd"))
    {
        ft_cd(msh, "cd ..");
    }
    else if (!ft_strncmp(msh->cmd[k], "export", 6))
    {
        ft_print_export(msh);
    }
}