
#include <sys/file.h>
#include "minishell.h"
#include "utils/msh_utils.h"

#define RED_SMALL 1
#define RED_LARG 2
#define DOUBLE_LARG 3
#define HERE_DOC 4
#define CREATE_FILE O_CREAT | O_RDWR, 0644


int getTmpFile(char **tokens, int *j) //here_doc
{
	char *line;
	int tFileFd;
	char *tmp;
	char *limiter;

	limiter = ft_strdup(tokens[(*j) + 1]);
	line = NULL;
	tFileFd = open("tmpFile", O_CREAT | O_RDWR, 0644);
	printf("fd = %d\n", tFileFd);
	write(1, "> ", 2);
	get_next_line(STDIN_FILENO, &line);
	while (ft_strcmp(line, limiter))
	{
		tmp = line;
		write(tFileFd, line, ft_strlen(line));
		write(tFileFd, "\n", 1);
		write(1, "> ", 2);
		get_next_line(STDIN_FILENO, &line);
		free(tmp);
	}
	free(line);
	close(tFileFd);
	return (tFileFd);
}

int	parseHereDoc(t_cmd *cmd_s, int *j)
{
	cmd_s->here_doc = 1;
	getTmpFile(cmd_s->cmdTokens, j);
	*cmd_s->fileInFd = open("tmpFile", O_RDONLY, 0644);
	(*j) += 1;
	return (HERE_DOC);
}


int getRedLargeFd(char **tokens, int *j)
{
	int fileFd;
	char *fileName;

	fileName = ft_strdup(tokens[(*j) + 1]);
	fileFd = open(fileName, O_TRUNC | O_CREAT | O_RDWR, 0644);
	free(fileName);
	return (fileFd);
}

int parseRedLarge(t_cmd *cmd_s, int *j)
{
	int	tmp;

	if (cmd_s->red_larg != 1)
	{
		cmd_s->red_larg = 1;
		*cmd_s->fileOutFd = getRedLargeFd(cmd_s->cmdTokens, j);
		(*j) += 1;
	}
	else
	{
		tmp = *cmd_s->fileOutFd;
		*cmd_s->fileOutFd = getRedLargeFd(cmd_s->cmdTokens, j);
		close(tmp);
		(*j) += 1;
	}
	return (RED_LARG);
}


int parseDoubleLarge(t_cmd *cmd_s, int *j)
{
	//int fileFd;
	//char *fileName;

//	fileName = ft_strdup(tokens[(*j) + 1]);
	cmd_s->double_larg = 1;
	*cmd_s->fileOutFd = open(cmd_s->cmdTokens[(*j) + 1], O_CREAT | O_RDWR | O_APPEND, 0644);
	(*j) += 1;
	return (DOUBLE_LARG);
}

//int parseRedSmall(char **tokens, int *j)
//{
//	int fileFd;
//	char *fileName;
//
//	fileName = ft_strdup(tokens[(*j) + 1]);
//	fileFd = open(fileName, O_RDONLY);
//	free(fileName);
//	return (fileFd);
//}

int parseRedSmall(t_cmd *cmd_s, int *j)
{
	//char *fileName;

	cmd_s->red_smal = 1;
	//fileName = ft_strdup(cmd_s->cmdTokens[(*j) + 1]);
	*cmd_s->fileInFd = open(cmd_s->cmdTokens[(*j) + 1], O_RDONLY);
	//free(fileName);
	(*j) += 1;
	return (RED_SMALL);
}

int check_ctrl_symbol(t_cmd *cmd_s, int *j)
{
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "<<"))
		return (parseHereDoc(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "<"))
		return (parseRedSmall(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], ">>"))
		return parseDoubleLarge(cmd_s, j);
	if (!ft_strcmp(cmd_s->cmdTokens[*j], ">"))
		return (parseRedLarge(cmd_s, j));
	return (0);
}
