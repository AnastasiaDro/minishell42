#include "minishell.h"
#include "enviroment/env_export_unset.h"

const char	*getLOGNAME(t_en_list *export_list)
{
	while (export_list)
	{
		if (!ft_strncmp(export_list->name, "LOGNAME", 7))
			return (export_list->value);
		export_list = export_list->next;
	}
	return (NULL);
}

void	ft_init(t_msh *msh, char **envp)
{
	char	*s1;

	msh->fd = 0;
	msh->len = 0;
	msh->quote = 0;
	msh->cntPipes = 0;
	msh->countTokens = 0;
	msh->envp_arr = envp;
	msh->export_list = NULL;
	msh->env_list = NULL;
	msh->envp_len = init_envp_list(envp, &(msh->export_list), &(msh->env_list));
	s1 = "HOME";
	ft_unset(msh, &s1);
	ft_add_variable(msh, ft_strdup(s1), ft_strjoin("/Users/", getLOGNAME(msh->export_list)));
}
