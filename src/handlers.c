/*
	идём по всем токенам, пока не встретимся с NULL
	каждый токен берем и смотрим, есть там равно или рнет.
	если void envAddVariable(t_msh *msh, char *name, char *value)

	TODO: если ключь уже существует в экпорте, перезаписывается без команды экпорт т.е KEY=VALUE
*/

#include "minishell.h"

void exportHandler(t_msh *msh, int i)
{
	while (msh->cmd[i])
	{
		if (!ft_strcmp(msh->cmd[i], "="))
		{
			envAddVariable(msh, msh->cmd[i - 1], msh->cmd[i + 1]);
			printf("=: %s i: %d\n", msh->cmd[i], i);
		}
		i++;
	}
}

int cerExportHandler(t_msh *msh, char **execArr)
{
	char *eq_ptr;
	char *name;
	char *value;
	int i;

	i = 1;
	while (execArr[i])
	{
		eq_ptr = ft_strchr(execArr[i], '=');
		if (eq_ptr)
		{
			*eq_ptr = '\0';
			name = ft_strdup(execArr[i]);
			value = ft_strdup(eq_ptr + 1);
			*eq_ptr = '=';
		}
		else
		{
			name = ft_strdup(execArr[i]);
			value = NULL;
			printf("token = %s\n", execArr[i]);
		}
		envAddVariable(msh, name, value);
		i++;
	}
	return (1);
}