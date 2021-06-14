//
// Created by Cesar Erebus on 6/11/21.
//

#include "minishell.h"
#include "exit_codes.h"

void ft_parser(t_msh *msh)
{
    int i = 0;
    // char *token = NULL;
    // printf("before msh->line: %s\n", msh->line);
    // printf("befire msh->len: %d\n", msh->len);
    // token = ft_strsep(&msh->line, " ");
    while (msh->line[i] != '\0')
    {
        printf("char: |%c|\n", msh->line[i]);
        if (msh->line[i] == '\"')
        {
            int j = 0;
            if (msh->line[j] == '\"')

                j++;
        }
        i++;

    }
    // printf("after msh->line: %s\n", msh->line);
    // printf("after msh->len: %d\n", msh->len);
}
