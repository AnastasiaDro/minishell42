#include "minishell.h"
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// void loop()
// {
// 	char *line;
// 	char **args;
// 	int status;
// }

int main(int ac, char **av)
{
	int str[3];
	int len;

	while (1)
	{
		len = read(0, &str, 3);
		if (str == '\4')
			break;
	// 	else if (len > 0)
	}
	return (0);
}