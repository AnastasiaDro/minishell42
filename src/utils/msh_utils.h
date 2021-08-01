#ifndef MSH_UTILS_H
# define MSH_UTILS_H
# include "../minishell.h"

void	move_index(char *str, int *i, char c);
void	ft_lstFree(t_list *list);
void	ft_freeEnList(t_en_list *list);
int		ft_freeStringsArr(char **stringsArr);

#endif
