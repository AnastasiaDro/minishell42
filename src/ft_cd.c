#include "minishell.h"

// static void	setPwd(char *dirName)
// {
	
// }

void	ft_cd(const char *path)
{
	chdir(path);
}

// int	main()
// {
// 	sigset_t pe;
// 	ft_cd("/Users/jkeitha");
// 	return (0);
// }