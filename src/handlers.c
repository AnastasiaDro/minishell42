/*
	идём по всем токенам, пока не встретимся с NULL
	каждый токен берем и смотрим, есть там равно или рнет.
	если void ft_add_variable(t_msh *msh, char *name, char *value)

	TODO: если ключь уже существует в экпорте, перезаписывается без команды экпорт т.е KEY=VALUE
*/

#include "minishell.h"

void exportHandler(t_msh *msh, int i)
{
	while (msh->cmd[i])
	{
		if (!ft_strcmp(msh->cmd[i], "="))
		{
			ft_add_variable(msh, msh->cmd[i - 1], msh->cmd[i + 1]);
			printf("=: %s i: %d\n", msh->cmd[i], i);
		}
		i++;
	}
}