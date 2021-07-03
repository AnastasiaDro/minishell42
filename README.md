Тут начинается minishell

fork() - 
execve() - 
wait() - 
chdir() - 

-L/usr/local/opt/readline/lib

-I/usr/local/opt/readline/include

-L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline


	// {
	// 	// rl_redisplay();
	// 	// printf("cd: %s: No such file or directory\n", path);
	// 	char *s1 = ft_strjoin("cd: ", path);
	// 	char *s2 = ft_strjoin(s1, ": No such file or directory");
	// 	rl_replace_line(s2, 0);
	// 	rl_on_new_line();
	// 	rl_redisplay();
	// 	write(1, "\n", 1);
	// }