#include "libft.h"
#include <stdio.h>

size_t	ft_strcspn(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1 && (ft_strchr(s2, *s1++) == NULL))
		i++;
	return (i);
}
