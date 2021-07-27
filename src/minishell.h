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
#include "utils/msh_utils.h"
# define NAME "msh: "
# define ARGNUM_ERR "Invalid arguments number!\n"
# define COMMAND_ERR "command not found"
# define SYNTAX_ERR "syntax error near unexpected token"
#define NEW_LINE	"newline"

#define SQUOTES 1
#define DQUOTES 2

// builtin привести к одному регистру
#define FT_ECHO "echo"
#define FT_CD "cd"
#define FT_PWD "pwd"
#define FT_EXPORT "export"
#define FT_UNSET "unset"
#define FT_ENV "env"
#define FT_EXIT "exit"

// // commandDataStructure
// typedef struct s_SimpleCommand
// {
// 	int numberOfAvailableArguments;
// 	int numberOfArguments;
// 	char **arguments;
// }t_SimpleCommand;

// typedef struct s_Command
// {
// 	int numberOfAvailableSimpleCommands;
// 	int umberOfSimpleCommands;
// 	t_SimpleCommand **simpleCommands;
// 	char *outFile;
// 	char *inFile;
// 	char *errFile;
// 	// int background;
// 	// t_Commanmd currentCommand;
// 	t_SimpleCommand *currentSimpleCommand;
// }t_Commanmd;

typedef struct s_msh // main struct
{
//	int		fd;
	int		len;
	int		quote;
	char	**cmd;
	int		cntPipes;
	int		countTokens;
	char     *line;

	//добавила Настя
	t_en_list 	*export_list;//отсортированный список переменных среды
	t_en_list   *env_list; //несортированный список переменных среды
	char 		**envp_arr;
    int     	envp_len;  //длина списка переменных среды
	int			**fd;
	int 		commands_num;
}               t_msh;

typedef struct  s_command
{
	//индекс команды в списке
	int com_num;
	int here_doc;
	int red_smal;
	int red_larg;
	int double_larg;
	int tmpFileFd;
	int fileInFd;
	int fileOutFd;
	int red_larg_fileFd;
	int red_small_fd;
	char *command;
}				t_command;

// parsing
void parser(t_msh *msh, char *line);

// lexer
char *lexer(t_msh *msh, char **line);

// exec
void	exec(t_msh *msh);

// errors
void ft_error(ssize_t err_no, const char *msg);

// init
//void	ft_init(t_msh *msh);
void ft_init(t_msh *msh, char **envp);

// builtin
void	ft_exit();
void	ft_echo(char **av);
void	ft_pwd();
void ft_cd(t_msh *msh, const char *path);
// void	ft_echo(t_msh *msh, int arguments);

// readline
void rl_replace_line();
int parseHereDoc(int i,  int out, t_msh *msh);

// handlers
void	exportHandler(t_msh *msh, int i);
void ft_add_variable(t_msh *msh, char *name, char *value);

#endif