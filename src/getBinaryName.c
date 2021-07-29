#include "minishell.h"

char	*getBinaryName(char *command)
{
	char *s;

	s = command;
	if (!ft_strncmp(s, "/bin/", 5))
	{
		command = ft_substr(&(s[5]), 0, ft_strlen(&(s[5])));
		free(s);
	}
	return (command);

}
