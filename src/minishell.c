#include "minishell.h"

int main(int ac, char **av, char **envp)
{
	t_msh msh;
	(void)ac;
	(void)av;
	(void)envp;
	ft_init(&msh);
	ft_memset(&msh, 0, sizeof(msh));
	while (1)
	{
		msh.line = readline("msh: ");
		msh.len = ft_strlen(msh.line);
		if (msh.len > 0)
		{
			add_history(msh.line);
			ft_parser(&msh);
		}
		free(msh.line);
		msh.line = NULL;
	}
	return (0);
}