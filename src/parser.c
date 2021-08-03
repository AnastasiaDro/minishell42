#include "minishell.h"
#include "enviroment/env_export_unset.h"

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

void inQuotes1(char **line)
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
    else if (**line == '>' || **line == '|' || **line == '<' || **line == '$' || **line == '=')
        ++*line;
    else
    {
        while (*line && **line && !ft_strchr(" $>=|<", **line))
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
    char *tmp;
    t_list *token;

    token = NULL;
    while (line && *line)
    {
        while (*line == ' ')
            line++;
        while ((tmp = ft_strsep(&line, "|")) != NULL)
        {
        	ft_lstadd_back(&token, ft_lstnew(ft_strtrim(tmp, " ")));
        }
    }

    msh->commands_num = ft_lstsize(token); //добавили в структуру msh число команд
    msh->cmd = malloc(( msh->commands_num + 1) * sizeof(char *));
    msh->cmd[ msh->commands_num] = NULL;
    t_list *tmp1 = token;
    int i = 0;
    while (tmp1)
    {
        msh->cmd[i] = ft_strdup(tmp1->content);
        i++;
        tmp1 = tmp1->next;
    }
	ft_lstFree(token);
    // мы поделили строку на куски по пайпам, они лежат в минишелл cmd
    // TODO: тут оставили утечку
}
