
#ifndef ENV_LIST_H
# define ENV_LIST_H

//список переменных среды
typedef struct s_en_list
{
	char			*name;
	char			*value;
	struct s_en_list	*next;
}				t_en_list;

int         env_lstsize(t_en_list *lst);

t_en_list	*env_lstlast(t_en_list *lst);

void       	env_lstadd_back(t_en_list **lst, t_en_list *new);

t_en_list	*env_lstnew(char *str);

void	env_lstadd_front(t_en_list **lst, t_en_list *new);

t_en_list       *env_parsed_lstnew(char *name, char *value);

#endif