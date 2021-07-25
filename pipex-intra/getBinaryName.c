#include "libft/libft.h"

void	getBinaryName(char **command)
{
	char	*s;
	int		i;

	s = *command;
	i = 0;
	while (s[i])
	{
		if (s[i] == ' ')
		{
			if (!ft_strncmp(s, "/bin/", 5))
			{
				*command = ft_substr(&(s[5]), 0, i - 5);
				return ;
			}
			*command = ft_substr(s, 0, i);
			return ;
		}
		i++;
	}
}
