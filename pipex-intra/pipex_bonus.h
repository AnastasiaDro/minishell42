#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# define HERE_DOC 1
# include "pipex.h"

typedef struct s_bstruct
{
	int		argc;
	int		flag;
	int		commands_num;
	char	**argv;
	char	**pathList;
}				t_bstruct;

void	initStruct(t_bstruct *bstruct, int argc, char *argv[], char **envp);
int		bonusParseCmd(int ***fd, int current_index, t_bstruct *bStruct);
int		bonusParseMiddleCommands(int **fd, t_bstruct *bstruct);
int		bonusParseHereDoc(int **fd, t_bstruct *bStruct);
int		bonusCheckHereDoc(char **argv);
int		bonusGetTmpFile(char **argv);
int		bonusGetStdin(int **fd, char *command, int tmpFd, t_bstruct *bStruct);
int		bonusParsePipesOnly(int **fd, t_bstruct *bStruct);
int		bonusParseLastRedirect(int **fd, t_bstruct *bS);
int		bonusLastCommand(int **fd, t_bstruct *bS);
int		parseFirstCommand(int **fd, t_bstruct *bStruct);
void	bonusCloseAllFds(int ***fd, int commands_num);
void	bonusClean(int **fd, t_bstruct *bStruct);
void	checkFileFd(int fileFd, char *name, t_bstruct *bS, int **fd);
void	checkExecArr(char **execArr, int **fd, t_bstruct *bS);

#endif
