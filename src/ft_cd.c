#include "minishell.h"

static void setPwd(t_msh *msh)
{
	char *dir;
	// char buf[1024];

	dir = "jkeitha";
	while (msh->envp_list)
	{
		if (!strncmp(msh->envp_list->name, "PWD", 3)) // TODO: change strcmp to ft_strcmp
		{
			printf("currentValue: %s\n", msh->envp_list->value);
			free(msh->envp_list->value);
			printf("currentValue:1 %s\n", msh->envp_list->value);
			msh->envp_list->value = dir;
			printf("currentValue:3 %s\n", msh->envp_list->value);
		}
		msh->envp_list = msh->envp_list->next;
	}
}

void ft_cd(t_msh *msh, const char *path)
{
	setPwd(msh);
	chdir(path);
}

// int	main()
// {
// 	sigset_t pe;
// 	ft_cd("/Users/jkeitha");
// 	return (0);
// }