#include "minishell.h"

// void loop()
// {
// 	char *line;
// 	char **args;
// 	int status;
// }

// pid_t id;

// id = fork();
// typeof(id) idi;
// printf("Hello\n");
// printf("2: %d\n", id);

// // printf("3: %d\n", fork());
// return (0);

int main()
{
	t_msh *msh; // основная структура
	int str[3];
	int len;

	while (1)
	{
		len = read(0, &str, 3);
		if (str == '\4')
			break;
		else if (len > 0)
			return (0);
	}
	return (0);
}