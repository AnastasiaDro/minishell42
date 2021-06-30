#include "minishell.h"

void	ft_pwd(void)
{
	char	buf[1024];
	char	*dir;

	dir = getcwd(buf, 1024);
	printf("%s\n", dir);
}
