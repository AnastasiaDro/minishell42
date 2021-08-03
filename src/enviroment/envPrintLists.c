#include "../minishell.h"

void ft_print_export( t_msh *msh)
{
	t_en_list *vars;
	char *value;

	vars = msh->export_list;
	while (vars)
	{
		value = vars->value;
		if (value != NULL)
			printf("declare -x %s=\"%s\"\n", vars->name, vars->value);
		else
		{
			if (vars->name)
			{
				printf("declare -x %s\n", vars->name);
			}
		}
		vars = vars->next;
	}
}

void ft_print_env(t_msh *msh)
{
	t_en_list   *vars;
	char        *value;

	vars = msh->env_list;
	while (vars)
	{
		value = vars->value;
		if (value != NULL)
			printf("%s=\"%s\"\n", vars->name, vars->value);
		vars = vars->next;
	}
}
