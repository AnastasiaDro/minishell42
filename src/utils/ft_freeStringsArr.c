#include <stdlib.h>

int	ft_freeStringsArr(char **stringsArr)
{
	int	i;

	i = 0;
	while (stringsArr[i])
	{
		free(stringsArr[i]);
		stringsArr[i] = NULL;
		i++;
	}
	free(stringsArr);
	stringsArr = NULL;
	return (0);
}
