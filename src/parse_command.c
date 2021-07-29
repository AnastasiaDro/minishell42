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
	printf("file fd = %d\n", fileFd);
	free(fileName);
	return (fileFd);

}

int parse_double_larg(char **tokens, int *j)
{
	int fileFd;
	char *fileName;

	fileName = ft_strdup(tokens[(*j)+1]);
	fileFd = open(fileName, O_CREAT | O_RDWR, 0644);
	printf("file fd = %d\n", fileFd);
	free(fileName);
	return (fileFd);
}

int parse_red_small(char **tokens, int *j)
{
	int fileFd;
	char *fileName;

	fileName = ft_strdup(tokens[(*j)+1]);
	fileFd = open(fileName, O_RDONLY);
	printf("fileFd = %d\n", fileFd);
	printf("filename = %s\n", fileName);
	free(fileName);
	return (fileFd);
}


int check_ctrl_symbol(t_cmd *cmd_s, int *j)
{
		if (!ft_strcmp(cmd_s->cmdTokens[*j], "<<"))
		{
			printf("HERE_DOC j = %d\n", *j);
			cmd_s ->here_doc = 1;
			cmd_s->fileInFd = getTmpFile(cmd_s->cmdTokens, j);
			printf("tmpFile id = %d\n", cmd_s->fileInFd);
			(*j) += 2; //сдвигаем указатель за лимитер
			return (HERE_DOC);
		}

		if(!ft_strcmp(cmd_s->cmdTokens[*j], "<"))
		{
			printf("RED_SMALL j = %d\n", *j);
			cmd_s->red_smal = 1;
			cmd_s->red_small_fd = parse_red_small(cmd_s->cmdTokens, j);
			(*j) += 1;
			return (RED_SMALL);
		}
		if(!ft_strcmp(cmd_s->cmdTokens[*j], ">>"))
		{
			printf("DOUBLE_LARG j = %d\n", *j);
			cmd_s->fileOutFd = parse_double_larg(cmd_s->cmdTokens, j); //
			cmd_s->double_larg = 1;
			(*j) += 1;
			return (DOUBLE_LARG);

		}
		if(!ft_strcmp(cmd_s->cmdTokens[*j], ">"))
		{
			cmd_s->red_larg = 1;
			cmd_s->red_larg_fileFd = parse_red_larg(cmd_s->cmdTokens, j);
			return (RED_LARG);
		}
		return (0);
	}

//
//int parse_command(t_msh *msh, int com_num)
//{
//	t_cmd	com_s;
////	char		**pathList;	//массив папок path
//	int			i;			//индекс для прохода по строке
////	int 		res;
//	int end;
//
//	i = 0;
//	if(check_ctrl_symbol(msh->cmd[com_num], &i, &com_s))
//		i++;
//
//	printf("cmd[i] = %c\n", msh->cmd[com_num][i]);
//	end = i;
//	while(msh->cmd[com_num][end] && (msh->cmd[com_num][end] != ' ' || msh->cmd[com_num][end] !='<' || msh->cmd[com_num][end] != '>'))
//		end++;
//	char *com = &msh->cmd[com_num][i];
//	execCerBuiltin(msh, com);
//	//обработку файла засунем в check_ctrl_symbol
////	res =
//	return (i);
//}


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
//	while(lexer_list)
//	{
//		printf("lexer_content = %s\n", lexer_list->content);
//		lexer_list = lexer_list->next;
//	}
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
	while(arr[i])
	{
		printf("arr[%d] = %s\n", i, arr[i]);
		i++;
	}
	return (arr);
}


//int parseSymbol(char *cmd_str, int *i, t_cmd *command)
//{
//	if (cmd_str[(*i)] == '<')
//	{
//		if (cmd_str[(*i) + 1] == '<')
//		{
//			(*i)++;
//			command->here_doc = 1;
//			return (HERE_DOC);
//		}
//		else
//		{
//			command->redir_small = 1;
//			(*i)++;					//сдвинули i на пробел
//			command->fdIn = get_fdIn(cmd_str, i, O_RDONLY);
//			return (RED_SMALL);
//		}
//
//	}
//	if (cmd_str[(*i)] == '>')
//	{
//		if (cmd_str[(*i) + 1] == '>')
//		{
//			return (DOUBLE_LARG);
//		}
//		else
//		{
//			(*i)++;
//			command->fdIn = get_fdIn(cmd_str, i, 1); //1 = создать новый файл и задать ему правильные права
//			//здесь в get_fdIn также смещаем i
//			return (RED_LARG);
//		}
//
//	}
//	return (0);
//}
//
//int parse_command(char *cmd_str, int num, char **fd, t_msh *msh)
//{
//	int i;
//	//num - это номер команды
//
//	int pid;
//	pid = fork();
//
//	if (pid == 0)
//	{
//		t_cmd cmd;
//		if (num == msh->commands_num-1)
//		{
//			dup2(fd[num+1][1], STDOUT_FILENO);//перенаправляем выход в пайп
//			close(fd[num + 1][1]);
//		}
//
//		if (num != 0) //если команда не первая
//		{
//			dup2(fd[num][0], STDIN_FILENO);
//			close(fd[num][0]);
//		}
//
//		i = 0;
//		parseSymbol(cmd_str, &i, &cmd); //здесь заполнила если есть - фд-шник файла на ввод с <
//		i++; //сдвинули указатель
//		move_index(cmd_str, &i, ' '); //теперь i на месте команды
//
//		//тут нужно взять саму команду (бинарник или fdIn)
//		setCommandFromStr(cmd_str, &i, &cmd); //взяли саму команду и заодно проверили, есть ли here_doc
//		//получили параллельно лимитер если есть here_doc
//		//TODO: обработать строку до конца со всеми ее редиректами каким-то циклом
//
//		//выполнить команду
//
//
//		cmd.execArr = getExecArr(cmd.command, pipexSplit(findPath(msh->export_list), ':')); //получаем массив для выполнения
//		//тут уже все фд-шники поменяны
//		closeAllFds(&msh->fd, msh->commands_num);
//		execve(cmd.execArr[0], cmd.execArr, NULL);
//		perror(NAME);
//		exit(1);
//	}

//}