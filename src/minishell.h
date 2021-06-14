#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <sys/wait.h>
#include <term.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <limits.h>
#include <termios.h>
#include <ncurses.h>
#include <errno.h>
#include "../libft/libft.h"

#define SQUOTES 1
#define DQUOTES 2

typedef struct s_msh // main struct
{
	int		fd;
	int		len;
	char	*line;
	int		quote;
}t_msh;

// parsing
void	ft_readl(t_msh *msh);
void	ft_parser(t_msh *msh);

// errors
void	ft_error(ssize_t err_no, const char *msg);

// init
void	ft_init(t_msh *msh);

// builtin
void	ft_exit();

// void	ft_echo(t_msh *msh, int arguments);
#endif