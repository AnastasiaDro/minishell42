#include "minishell.h"

void dollarSign(t_msh *msh, char *dollar)
{
	char	*token;
	char	*found;

	while ((token = ft_strsep(&dollar, " $")) != NULL)
	{
	//	write(1, "INSIDE\n", 7);
		if (ft_strlen(token) > 0)
		{
			if (*token == '?')
			{
				// ft_putstr_fd("msh: ", 2);
				ft_putnbr_fd(errno, 2);
				ft_putendl_fd("", 2);
				// ft_putendl_fd(": command not found", 2);
			}
			else
			{
				found = (char *)getValue(msh->export_list, token);
				if (found)
					printf("%s\n", found);
			}
		}
	}
	write(1, "IsdfaweafsdasdfNSIDE\n", 7);
}
