#include "minishell.h"

// void ft_echo(t_msh *msh, int arguments)
// {
// 	int nflag;

// 	if ()
// 		write(msh->fd, arguments, sizeof(arguments));
// }

int main(int argc, char *argv[])
{
	int nflag;

	/* This utility may NOT do getopt(3) option parsing. */
	if (*++argv && !strcmp(*argv, "-n"))
	{
		++argv;
		nflag = 1;
	}
	else
		nflag = 0;

	while (*argv)
	{
		(void)fputs(*argv, stdout);
		if (*++argv)
			putchar(' ');
	}
	if (!nflag)
		putchar('\n');

	return 0;
}