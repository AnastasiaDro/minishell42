#include "minishell.h"

int	checkCtrlSymbol(t_cmd *cmd_s, int *j)
{
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "<<"))
		return (parseHereDoc(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], "<"))
		return (parseRedSmall(cmd_s, j));
	if (!ft_strcmp(cmd_s->cmdTokens[*j], ">>"))
		return parseDoubleLarge(cmd_s, j);
	if (!ft_strcmp(cmd_s->cmdTokens[*j], ">"))
		return (parseRedLarge(cmd_s, j));
	return (0);
}
