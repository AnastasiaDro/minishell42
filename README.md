Тут начинается minishell

fork() - 
execve() - 
wait() - 
chdir() - 

while (1)
{
....
...
system("leak ./minishell");
}

-L/usr/local/opt/readline/lib

-I/usr/local/opt/readline/include

-L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline

[//]: #man about expansion
https://man7.org/linux/man-pages/man1/bash.1.html#EXPANSION

TODO: ${} $() $[], ||

TODO:
	cd: unset HOME, cd return(cd: HOME not set)
	чекать 0-й элемент массива в билдинах

на потом:
1) обработать след кейс: export NAME = VALUE (в оригинале с пробелом между "NAME" и "=" не работает)

TODO: bugs
	-cd
	-$: done

TODO: norminette
	-src/ft_cd.c: OK!(fix: segFault then unset HOME, keys: cd work)
	-src/ft_echo.c: OK!
	-src/ft_exit.c: OK!
	-src/ft_pwd.c: OK!
	-src/parser.c: Error!
	-src/parser.c: OK!
	