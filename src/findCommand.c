#include <unistd.h>
#include <stdlib.h>
#include "minishell.h"

char	*findCommand(char **pathList, char *command)
{
	int		i;
	char	*tmp;
	char	*command_path;

	i = 0;
	command_path = NULL;
	command = getBinaryName(command);
	while (pathList[i])
	{
		tmp = command_path;
		command_path = ft_strjoin(pathList[i], command);
		free(tmp);
		if (!access(command_path, 0))
			return (command_path);
		i++;
	}
	free(command_path);
	return (NULL);
}
