//
// Created by Cesar Erebus on 7/25/21.
//

#ifndef HERE_DOC_H
# define HERE_DOC_H

#include "../minishell.h"


int checkHereDoc(int i, t_msh *msh);
int closeFreeAllFds(int **fd); //закрывает и очищает файловые дескрипторы
int	getTmpFile(char *limiter);
int	mFree(char **pathlist);
void fdPathListClean(int **fd, char **pathlist);
void	checkFileFd(int fileFd, char *name, int **fd, char **pathList);



int	getStdin(int out, char *command, int tmpFd, char **pathList);
char	**getExecArr(char *command, char **pathList);
char	**pipexSplit(char const *s, char c);
char	*findPath(t_en_list *export_list);
char	**execArrSplit(char const *s, char c, int *arrLen);
char	*findCommand(char **pathList, char *command);
void	getBinaryName(char **command);
void	printError(char *command, int flag);

#endif
