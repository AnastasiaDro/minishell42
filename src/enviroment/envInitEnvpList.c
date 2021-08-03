//
// Created by Cesar Erebus on 8/3/21.
//
#include "../minishell.h"

void init_envp_list(t_msh *msh)
{
	int index;
	char *str;
	int i;
	int j;


	j = 1;
	i = 0;
	while(i < msh->envp_len)
	{
		if (!strncmp(msh->envp[i], "OLDPWD", 6))
			msh->envp[i] = "OLDPWD";
		env_lstadd_back(&msh->env_list, env_lstnew(msh->envp[i]));
		i++;
	}
	str = msh->envp[0];
	while (j < msh->envp_len)
	{
		i = 0;
		while (i < msh->envp_len)
		{
			if (msh->envp[i] == NULL)
			{
				i++;
				continue;
			}
			else {
				if (ft_strncmp(msh->envp[i], str, ft_strlen(msh->envp[i])) <= 0)
				{
					str = msh->envp[i];
					index = i;
				}
			}
			i++;
		}
		if (str != NULL)
		{
			env_lstadd_back(&msh->export_list, env_lstnew(str));
		}
		msh->envp[index] = NULL;
		str = &msh->c;
		j++;
	}
	//вернем длину количества аргументов
}