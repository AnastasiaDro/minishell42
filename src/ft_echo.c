#include "minishell.h"

void	ft_echo(char **av)
{
	int	i;
	int nflag;

	while (*++av && !strncmp(*av, "-n", 2))
	{
		i = 1;
		while((*av)[i] == 'n')
			i++;
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

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	ft_echo(av);
// 	return (0);
// }