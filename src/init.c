#include "minishell.h"
#include "enviroment/envAddNew.h"

const char	*getValue(t_en_list *export_list, const char *key)
{
	t_en_list *tmp;

	tmp = export_list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, key))
			return (tmp->value);
		tmp = tmp->next;
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
	msh->envp = envp;
	msh->export_list = NULL;
	msh->env_list = NULL;
	msh->c = (char)255;
	msh->envp_len = (int)ft_arrlen(envp);
	//msh->envp_len = envInitEnvpList(envp, &(msh->export_list), &(msh->env_list));
	envInitEnvpList(msh);
	s1 = "HOME";
	envUnset(msh, &s1);
	envAddVariable(msh, ft_strdup(s1), ft_strjoin("/Users/", getValue(msh->export_list, "LOGNAME")));
}
