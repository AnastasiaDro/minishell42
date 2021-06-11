#ifndef MINISHELL_H
#define MINISHELL_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../libft/libft.h"

typedef struct s_msh // main struct
{
	int fd;
	char *line;
	int	len;
}t_msh;

// parsing
void	ft_parse(t_msh *msh, char str, int len);
//void ft_parser(t_msh *msh);

// builtin
// void	ft_echo(t_msh *msh, int arguments);
#endif