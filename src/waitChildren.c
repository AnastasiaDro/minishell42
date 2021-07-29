#include <sys/wait.h>
#include <unistd.h>

void	waitChildren(void)
{
	while (1)
	{
		if (wait(NULL) == -1)
			break ;
	}
}
