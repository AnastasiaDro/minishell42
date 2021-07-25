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
    else if (**line == '>' || **line == '|' || **line == '<' || **line == '$')
        ++*line;
    else
    {
        while (*line && **line && !ft_strchr(" $>|<", **line))
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
        if (!ft_strcmp(msh->cmd[i], "|"))
        {
            msh->cntPipes++;
            printf("cntPipes: %d\n", msh->cntPipes);
        }
        printf("currentToken: %s\n", token->content);
        token = token->next;
    }
    msh->cmd[++i] = 0;
    i = 0;
    if (!strncmp(msh->cmd[i], "echo", 4))
    {
        ft_echo(msh->cmd);
    }
    else if (!strncmp(msh->cmd[i], "pwd", ft_strlen(msh->cmd[i])))
    {
        ft_pwd();
    }
    else if (!strncmp(msh->cmd[i], "env", 3))
    {
        ft_print_env(msh);
    }
    else if (!strcmp(msh->cmd[i], "cd"))
    {
        ft_cd(msh, "cd ..");
    }
    else if (!strncmp(msh->cmd[i], "export", 6))
    {
        ft_print_export(msh);
    }
    else if (!strncmp(msh->cmd[i], "unset", ft_strlen(msh->cmd[i])))
    {

		if (msh->cmd[i+1] != NULL)
            ft_unset(msh, &(msh->cmd[i+1]));
    }
    else if (!ft_strcmp(msh->cmd[i], "<<"))
	{
		printf("Here!\n");
		parseHereDoc(i, 1, msh);
	}
}
