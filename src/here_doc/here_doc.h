//
// Created by Cesar Erebus on 7/25/21.
//

#ifndef HERE_DOC_H
# define HERE_DOC_H

#include "../minishell.h"


int	getTmpFile(char *limiter);
int	getStdin(int out, char *command, int tmpFd, char **pathList);
char	**getExecArr(char *command, char **pathList);
char	**pipexSplit(char const *s, char c);
char	*findPath(t_en_list *export_list);
char	**execArrSplit(char const *s, char c, int *arrLen);
char	*findCommand(char **pathList, char *command);
void	getBinaryName(char **command);

#endif
