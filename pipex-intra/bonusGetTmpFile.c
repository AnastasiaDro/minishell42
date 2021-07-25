#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"
#include "libft/bonus.h"
#include "get_next_line/get_next_line.h"

int	bonusGetTmpFile(char **argv)
{
	char	*line;
	int		tFileFd;
	char	*tmp;

	line = NULL;
	tFileFd = open("tmpFile", O_CREAT | O_RDWR, 0644);
	write(1, "> ", 2);
	get_next_line(STDIN_FILENO, &line);
	while (ft_strcmp(line, argv[2]))
	{
		tmp = line;
		write(tFileFd, line, ft_strlen(line));
		write(tFileFd, "\n", 1);
		write(1, "> ", 2);
		get_next_line(STDIN_FILENO, &line);
		free(tmp);
	}
	free(line);
	return (tFileFd);
}
