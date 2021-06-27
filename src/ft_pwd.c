#include "minishell.h"

void	ft_pwd(void)
{
	char	*buf;
	char	*dir;

	buf = NULL;
	dir = getcwd(buf, 4096);
	printf("%s\n", dir);
}
