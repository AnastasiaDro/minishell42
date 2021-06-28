#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/cdefs.h>

int	main(int argc,char **argv,char **envp)
{
    printf("Запуск CHILD с arg1, arg2 ...\n");
    execve("CHILD.EXE",argv,envp);
    perror("Ошибка EXEC");
    exit(1);
}


#include "minishell.h"

void	ft_echo(char **av)
{
	int nflag;
	int	i;
	// *++av;
	while (*++av && !strncmp(*av, "-n", 2))
	{
		// printf("here\n");
		i = 1;
		while((*av)[i] == 'n')
		{
			// write(1, "2-nd while\n", 11);
			i++;
		}
		if ((*av)[i] == '\0')
			nflag = 1;
		else 
		{
			nflag = 0;
			break;
		}
	}
	while (*av)
	{
		write(STDOUT_FILENO, *av, strlen(*av));
		if (*++av)
			write(STDOUT_FILENO, " ", 1);
	}
	if (!nflag)
		write(STDOUT_FILENO, "\n", 1);
}

int main(int ac, char **av)
{
	(void)ac;
	ft_echo(av);
	return (0);
}