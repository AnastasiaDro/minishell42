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

void cerExportHandler(t_msh *msh, t_cmd *cmd_s, int *j)
{
	//пока у нас не закончились токены после слова экспорт
	char *eq_ptr;
	char *name;
	char *value;

	while (cmd_s->cmdTokens[*j])
	{
		printf("token = %s\n", cmd_s->cmdTokens[(*j)]);
		//если внутри токена "="
		//то мы делаем берем имя и значение после знака равно
		printf("1 cmd_s->cmdTokens[*j + 1] = %s\n", cmd_s->cmdTokens[*j + 1]);
		eq_ptr = ft_strchr(cmd_s->cmdTokens[(*j) + 1], '=');

		if (eq_ptr)
		{
			*eq_ptr = '\0';
			printf("2 cmd_s->cmdTokens[*j] = %s\n", cmd_s->cmdTokens[*j]);
			name = ft_strdup(cmd_s->cmdTokens[(*j) + 1]);
			value = eq_ptr + 1;
			*eq_ptr = '=';
			(*j)++;
		}
		else
		{
			(*j)++;
			name = cmd_s->cmdTokens[*j];
			value = NULL;
			printf("token = %s\n", cmd_s->cmdTokens[(*j)]);
		}
		ft_add_variable(msh, name, value);
		(*j)++;
	}
}