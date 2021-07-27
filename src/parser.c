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

t_cmd   *getCMD(t_msh *msh, int i)
{
    int j;
    t_cmd *cmd_s;

    cmd_s = malloc(sizeof(t_cmd));
    //нужно заполнить в сьруктуре массив токенов
    cmd_s->com_num = i;
    cmd_s->command = msh->cmd[i]; // наверно можем без этого
    
    j = 0;
    //пример
    cmd_s->tokens = malloc(sizeof(char *) * 3);
    cmd_s->tokens[2] = NULL;
    // while (cmd_s->tokens[++j])
    while ((*msh->cmd[i])++)
    {
        cmd_s->tokens[j] = lexer(msh, &msh->cmd[i]);
         printf("&msh->cmd[%d] = %s\n", i, msh->cmd[i]);
        printf("cmd_s->tokens[%d] = %s\n", j, cmd_s->tokens[j]);
        j++;
    }

    
    //cmd_s->tokens = lexer(msh, &msh->cmd[i]);
    ////
   // j = -1;
   // while (msh->cmd[++j])
   // {
  //      msh->cmdArr[j]->tokens[j] = lexer(msh, &msh->cmd[j]);
   // }
////
    //char **cmd
     

    // i = -1;
    //while (++i < msh->commands_num)
    //{
   //     msh->cmdArr[i]->tokens
    //}
    return (cmd_s);
}

void    fillCMDArr(t_msh *msh)
{
    int i;

    i = -1;
    msh->cmdArr = malloc(sizeof(t_cmd *) * msh->commands_num);
    while (++i < msh->commands_num)
    {
        msh->cmdArr[i] = getCMD(msh, i);
        // printf("msh->cmd[i] %s\n", msh->cmd[i]);
        i++;
    }
}

void parser(t_msh *msh, char *line)
{
    int     i;
    char    *tmp;
    int     lstsize;
    t_list  *lsttmp;
    t_list  *token;

    token = NULL;
    while (line && *line)
    {
        while (*line == ' ')
            line++;
        while ((tmp = ft_strsep(&line, "|")) != NULL)
        {
            ft_lstadd_back(&token, ft_lstnew(tmp));
        }
    }
    lstsize = ft_lstsize(token);
    msh->cmd = malloc((lstsize + 1) * sizeof(char *));
    msh->cmd[lstsize] = NULL;
    lsttmp = token;
    i = -1;
    while (lsttmp)
    {
        msh->cmd[++i] = ft_strdup(lsttmp->content);
        lsttmp = lsttmp->next;
    }
    msh->commands_num = i + 1;
    fillCMDArr(msh);
    // TODO: тут оставили утечку
}
