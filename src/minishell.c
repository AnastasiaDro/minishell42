#include "minishell.h"

void	ft_prompt(void)
{
	write(1, "msh:", 4);
}

int main()
{
	t_msh	msh; 		// основная структура
	char	str[4];		// char **str;
	int		len;

	ft_prompt();
	ft_bzero(str, sizeof(char) * 4);
	while (1)
	{
		len = read(0, &str, 3);
		if (str[0] == '\4')
			break ;
		if (len > 0)
			ft_parse(&msh, str, len);
		if (str[0] == '\n');
		if (str[0] == '\177');
	}
	return (0);
}