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

int parse_red_larg(char *cmd_str, int *i)
{
	int fileFd;
	int end;
	char *fileName;

	move_index(cmd_str, i, ' ');
	printf("cmd_str[*i] = 22%c22\n", cmd_str[*i]);
	printf("&cmd_str[*i]%s\n", &cmd_str[*i]);
	end = *i;
	while(cmd_str[end] && cmd_str[end] != ' ')
		end++;
	printf("end = %d\n", end);
	printf("cmd_str[end] = %c\n", cmd_str[end]);
	cmd_str[end] = '\0';
	printf("cmd_str = %s\n", cmd_str);
	fileName = ft_strdup(&cmd_str[*i]);
	cmd_str[end] = ' ';
	*i = end;
	fileFd = open(fileName, O_TRUNC | O_CREAT | O_RDWR, 0644);
	free(fileName);
	return (fileFd);
}

int parse_double_larg(char *cmd_str, int *i)
{
	int fileFd;
	int end;
	char *fileName;

	move_index(cmd_str, i, ' ');
	printf("cmd_str[*i] = 22%c22\n", cmd_str[*i]);
	printf("&cmd_str[*i]%s\n", &cmd_str[*i]);
	end = *i;
	while(cmd_str[end] && cmd_str[end] != ' ')
		end++;
	printf("end = %d\n", end);
	printf("cmd_str[end] = %c\n", cmd_str[end]);
	cmd_str[end] = '\0';
	printf("cmd_str = %s\n", cmd_str);
	fileName = ft_strdup(&cmd_str[*i]);
	cmd_str[end] = ' ';
	*i = end;
	fileFd = open(fileName, O_CREAT | O_RDWR, 0644);
	printf("file fd = %d\n", fileFd);
	free(fileName);
	return (fileFd);
}

int check_ctrl_symbol(char *cmd_str, int *i)
{
	move_index(cmd_str, i, ' '); //дошли до начала символов
	int fd;

	fd = -2;
	if (cmd_str[*i] == '<')
	{
		if (cmd_str[*i + 1] == '<')
		{
			*i += 2;
			printf("HERE_DOC i = %d\n", *i);
			return (HERE_DOC);
		}
		(*i)++;
		printf("RED_SMALL i = %d\n", *i);

		return (RED_SMALL);
	}
	if (cmd_str[*i] == '>')
	{
		if (cmd_str[*i + 1] == '>')
		{
			*i += 2;
			printf("DOUBLE_LARG i = %d\n", *i);
			parse_double_larg(cmd_str, i);
			return (DOUBLE_LARG);
		}
		(*i)++;
		printf("RED_LARG i = %d\n", *i);
		printf("cmd_str[*i] = 11%c11\n", cmd_str[*i]);
		parse_red_larg(cmd_str, i);
		return (RED_LARG);
	}
	return (0);
}


int parse_command(t_msh *msh, int com_num)
{
	t_command	command;
	char		**pathList;	//массив папок path
	int			i;			//индекс для прохода по строке
	int			symb;
	int			fileFd;


	i = 0;
	symb = check_ctrl_symbol(msh->cmd[com_num], &i);
	//обработку файла засунем в check_ctrl_symbol


	return (i);
}



//int parseSymbol(char *cmd_str, int *i, t_command *command)
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
//		t_command cmd;
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