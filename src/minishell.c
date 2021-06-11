#include "minishell.h"
#include "../libft/libft.h"

void ft_prompt(void)
{
	write(1, "msh:", 4);
}

// int main(int ac, char **av, char **env)
int main()
{
	t_msh msh;	 // основная структура
	char str[1]; // char **str;
	int len;
	ft_memset(&msh, 0, sizeof(msh));
	ft_prompt();
	msh.line = NULL;
	while (1)
	{
		len = read(0, str, 1);
		if (str[0] == '\4')
			break ;
		else if (str[0] == '\n')
		{
			str[0] = '\0';
			printf("Line: %s\n", msh.line);
		}
		else if (str[0] != '\t' && str[0] != '\n')
			ft_parse(&msh, str[0], len);

		// if (str[0] == '\177')
		// 	break ;
	}
	return (0);
}