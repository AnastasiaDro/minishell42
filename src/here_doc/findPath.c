

#include "../../libft/libft.h"
#include "../minishell.h"

char	*findPath(t_en_list *export_list)
{
	t_en_list *p;

	p = export_list;
	while (p)
	{
		if (!ft_strcmp("PATH", p->name))
			return (p->value);
		p = p->next;
	}
	return (NULL);
}
