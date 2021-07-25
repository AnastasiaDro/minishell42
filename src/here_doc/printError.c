#include <errno.h>
#include <stdio.h>
#include "unistd.h"
#include "../../libft/libft.h"
#include "../minishell.h"


void	printError(char *command, int flag)
{
	char	*prefix;

	if (flag == 0)
	{
		prefix = ft_strjoin(NAME, command);
		perror(prefix);
		free(prefix);
		return ;
	}
	if (flag == 1)
	{
		errno = 127;
		write(2, NAME, ft_strlen(NAME));
		write(2, command, ft_strlen(command));
		write(2, ": ", 2);
		write(2, COMMAND_ERR, ft_strlen(COMMAND_ERR));
		write(2, "\n", 1);
	}
}
