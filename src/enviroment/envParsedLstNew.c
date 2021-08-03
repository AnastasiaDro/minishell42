
#include "../minishell.h"

t_en_list       *envParsedLstNew(char *name, char *value)
{
	t_en_list	*list;

	if (!(list = (t_en_list *)malloc(sizeof(t_en_list))))
		return (NULL);
	list->name = name;
	list->value = value;
	list->next = NULL;
	return (list);
}
