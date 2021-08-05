/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:40:46 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/05 21:42:15 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <term.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <limits.h>
# include <termios.h>
# include <ncurses.h>
# include <errno.h>
# include <sys/file.h>
# include "../libft/libft.h"
# include "environment/environment.h"
# include "utils/msh_utils.h"

# define NAME "msh: "
# define ARGNUM_ERR "Invalid arguments number!\n"
# define COMMAND_ERR "command not found"
# define RED_SMALL 1
# define RED_LARG 2
# define DOUBLE_LARG 3
# define HERE_DOC 4
# define SYNTAX_ERR "syntax error near unexpected token"
# define NEW_LINE "newline"
# define SQUOTES 1
# define DQUOTES 2
# define FT_ECHO "echo"
# define FT_CD "cd"
# define FT_PWD "pwd"
# define FT_EXPORT "export"
# define FT_UNSET "unset"
# define FT_ENV "env"
# define FT_EXIT "exit"

typedef struct s_msh
{
	char		c;
	int			one;
	int			len;
	int			**fd;
	int			zero;
	int			quote;
	char		**cmd;
	char		*line;
	char		**envp;
	int			dollar;
	int			envp_len;
	int			cntPipes;
	int			countTokens;
	int			commands_num;
	t_en_list	*env_list;
	t_en_list	*export_list;
}t_msh;

typedef struct s_cmd
{
	int		com_num;
	int		here_doc;
	int		red_smal;
	int		red_larg;
	int		double_larg;
	int		tmpFileFd;
	int		*fileInFd;
	int		*fileOutFd;
	int		red_larg_fileFd;
	int		red_small_fd;
	char	**cmdTokens;
}t_cmd;

void		parser(t_msh *msh, char *line);
int			dollarSign(t_msh *msh, char *dollar);
void		exec(t_msh *msh);
char		**hasTokens(t_cmd *cmd_s);
int			execEcho(t_msh *msh, char **comArr);
void		ft_error(ssize_t err_no, const char *msg);
void		ft_init(t_msh *msh, char **envp);
const char	*getValue(t_en_list *export_list, const char *key);
void		ft_exit(void);
void		ft_echo(char **av, int nflag);
int			ft_pwd(void);
int			ft_cd(t_msh *msh, const char *path);
void		rl_replace_line(void);
void		envAddVariable(t_msh *msh, char *name, char *value);
int			checkCtrlSymbol(t_cmd *cmd_s, int *j);
int			execCerBuiltin(t_msh *msh, char **comArr);
int			cerExportHandler(t_msh *msh, char **execArr);
void		cerExec(t_msh *msh);
void		waitChildren(void);
char		**lexer(char *s);
t_en_list	*getExportVar(t_en_list **export, char *key_name);
int			execBinary(t_msh *msh, char **execArr);
char		*getBinaryName(char *command);
char		**pipexSplit(char const *s, char c);
char		*findCommand(char **pathList, char *command);
void		printError(char *command, int flag);
int			initFds(t_msh *msh);
void		closeAllFds(int **fd, int commands_num);
char		*inQuotes(char *s, int *start);
void		envInitEnvpList(t_msh *msh);
int			ft_print_export( t_msh *msh);
int			ft_print_env(t_msh *msh);
int			parseHereDoc(t_cmd *cmd_s, int *j);
void		envUnset(t_msh *msh, char **names);
int			parseRedLarge(t_cmd *cmd_s, int *j);
int			parseDoubleLarge(t_cmd *cmd_s, int *j);
int			parseRedSmall(t_cmd *cmd_s, int *j);

#endif