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
#include "exit_codes.h"
#include "../libft/libft.h"
#include "env_list.h"

#define SQUOTES 1
#define DQUOTES 2

typedef struct s_msh // main struct
{
	int			fd;
	int			len;
	char		*line;
	int			quote;
//добавила Настя
	t_en_list 	*envp_list; //список переменных среды
	char 		**envp_arr; //массив переменных
    int     	envp_len;  //длина списка переменных среды
}               t_msh;



// parsing
void	ft_readl(t_msh *msh);
void	ft_parser(t_msh *msh);

// errors
void	ft_error(ssize_t err_no, const char *msg);

// init
//void	ft_init(t_msh *msh);
void ft_init(t_msh *msh, char **envp);

// builtin
void	ft_exit();

// readline
void	rl_replace_line();

// void	ft_echo(t_msh *msh, int arguments);



#endif