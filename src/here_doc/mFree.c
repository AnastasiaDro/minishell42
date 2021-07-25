#include "here_doc.h"

int	mFree(char **pathlist)
{
	int	i;

	i = 0;
	while (pathlist[i])
	{
		free(pathlist[i]);
		pathlist[i] = NULL;
		i++;
	}
	free(pathlist);
	pathlist = NULL;
	return (0);
}
