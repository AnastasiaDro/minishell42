#ifndef PIPEX_H
# define PIPEX_H
# define NAME "pipex: "
# define ARGNUM_ERR "Invalid arguments number!\n"
# define COMMAND_ERR "command not found"
# include <errno.h>
# include "unistd.h"
# include "libc.h"
# include "libft/libft.h"
# include "libft/bonus.h"

int		mFree(char **pathlist);
char	*findPath(char **envp);
char	**pipexSplit(char const *s, char c);
char	**getBinaryName(char **command);
char	*findCommand(char **pathList, char *command);
char	**execArrSplit(char const *s, char c, int *arrLen);
char	**getExecArr(char *command, char **pathList);
void	printError(char *command, int flag);
void	waitChildren(void);
void	simpleCheckFileFd(int fileFd, char *argv[], char **pathList);
void	simpleCheckExecArr(char **execArr, char **pathList);
int		simpleFirstCommand(int *fd, char **argv, char **pathList);
int		simpleLastCommand(int *fd, char *argv[], char **pathList);
void	simpleCloseFds(int *fd, int fileFd);

#endif
