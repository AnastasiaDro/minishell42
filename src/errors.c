#include "minishell.h"

void	ft_error(ssize_t err_no, const char *msg)
{
	if (err_no != 0)
		printf("Error[%zd]: %s\n", err_no, msg);
	errno = err_no;
}