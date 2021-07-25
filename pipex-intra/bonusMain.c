#include <unistd.h>
#include <stdlib.h>
#include "pipex.h"
#include "libft/libft.h"
#include "pipex_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	int			**fd;
	t_bstruct	bStruct;
	int			i;

	if (argc < 5)
	{
		write(1, ARGNUM_ERR, ft_strlen(ARGNUM_ERR));
		return (1);
	}
	i = 0;
	initStruct(&bStruct, argc, argv, envp);
	fd = malloc(bStruct.commands_num * sizeof (int *));
	while (i < bStruct.commands_num)
	{
		fd[i] = malloc(sizeof(int) * 2);
		pipe(fd[i]);
		i++;
	}
	if (bStruct.flag == HERE_DOC)
		bonusParseHereDoc(fd, &bStruct);
	else
		bonusParsePipesOnly(fd, &bStruct);
}
