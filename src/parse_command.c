//
// Created by Cesar Erebus on 7/27/21.
//
#include <sys/file.h>
#include "minishell.h"
#include "utils/msh_utils.h"

#define RED_SMALL 1
#define RED_LARG 2
#define DOUBLE_LARG 3
#define HERE_DOC	4
#define CREATE_FILE  O_CREAT | O_RDWR, 0644

int getTmpFile(char **tokens, int *j)	//here_doc
{
	char	*line;
	int		tFileFd;
	char	*tmp;
	char 	*limiter;

	limiter = ft_strdup(tokens[(*j)+1]);

	line = NULL;
	tFileFd = open("tmpFile", O_CREAT | O_RDWR, 0644);
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
	return (tFileFd);
}


int parse_red_larg(char **tokens, int *j)
{
	int fileFd;
	char *fileName;

	fileName = ft_strdup(tokens[(*j)+1]);
	fileFd = open(fileName, O_TRUNC | O_CREAT | O_RDWR, 0644);
	free(fileName);
	return (fileFd);

}

int parse_double_larg(char **tokens, int *j)
{
	int fileFd;
	char *fileName;

	write(1, "hh", 2);
	fileName = ft_strdup(tokens[(*j)+1]);


	fileFd = open(fileName, O_CREAT | O_RDWR | O_APPEND, 0644);
	//printf("file fd = %d\n", fileFd);
	free(fileName);
	return (fileFd);
}

int parse_red_small(char **tokens, int *j)
{
	int fileFd;
	char *fileName;

	fileName = ft_strdup(tokens[(*j)+1]);
	fileFd = open(fileName, O_RDONLY);
	free(fileName);
	return (fileFd);
}


int check_ctrl_symbol(t_cmd *cmd_s, int *j)
{
		if (!ft_strcmp(cmd_s->cmdTokens[*j], "<<"))
		{
		//	printf("HERE_DOC j = %d\n", *j);
			cmd_s ->here_doc = 1;
			cmd_s->fileInFd = getTmpFile(cmd_s->cmdTokens, j);
		//	printf("tmpFile id = %d\n", cmd_s->fileInFd);
			(*j) += 2; //сдвигаем указатель за лимитер
			return (HERE_DOC);
		}

		if(!ft_strcmp(cmd_s->cmdTokens[*j], "<"))
		{
			//printf("RED_SMALL j = %d\n", *j);
			cmd_s->red_smal = 1;
			cmd_s->fileInFd = parse_red_small(cmd_s->cmdTokens, j);
			(*j) += 1;
			return (RED_SMALL);
		}
		if(!ft_strcmp(cmd_s->cmdTokens[*j], ">>"))
		{
			//printf("DOUBLE_LARG j = %d\n", *j);
			cmd_s->fileOutFd = parse_double_larg(cmd_s->cmdTokens, j); //
			cmd_s->double_larg = 1;
			(*j) += 1;
			return (DOUBLE_LARG);

		}
		if(!ft_strcmp(cmd_s->cmdTokens[*j], ">"))
		{
			cmd_s->red_larg = 1;
			cmd_s->fileOutFd  = parse_red_larg(cmd_s->cmdTokens, j);
			(*j) += 1;
			return (RED_LARG);
		}
		return (0);
	}


char **lexer_again(char *s)
{
	t_list *lexer_list;

	int start = 0;
	int end;
	lexer_list = NULL;
	int lst_size = 0;

	while(s[start])
	{
		move_index(s, &start, ' ');
		end = start;
		while(s[end] && s[end] != ' ')
			end++;
		ft_lstadd_back(&lexer_list, ft_lstnew(ft_substr(s, start, end - start)));
		start = end;
	}
	t_list *tmp = lexer_list;
	lst_size = ft_lstsize(tmp);
	char **arr = malloc(sizeof(char *) * lst_size + 1);
	arr[lst_size] = NULL;

	int i = 0;
	tmp = lexer_list;
	while(tmp)
	{
		arr[i] = ft_strdup(tmp->content);
		tmp = tmp->next;
		i++;
	}
	i = 0;
//	while(arr[i])
//	{
//		printf("arr[%d] = %s\n", i, arr[i]);
//		i++;
//	}
	return (arr);
}
