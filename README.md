Тут начинается minishell

fork() - 
execve() - 
wait() - 
chdir() - 

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







// хлам из парсера 
i = 0;
    while (token) // TODO: проверить токенов на синтактическую ошибку
    {
        msh->cmd[i] = ft_strdup(token->content);
        printf("msh->cmd[%d]: %s\n", i, msh->cmd[i]);
        if (!ft_strcmp(msh->cmd[i], "|") || !token->next)
        {
            if (!ft_strcmp(msh->cmd[i], "|"))
                msh->cntPipes++;
            if (!token->next)
            {   
                if (msh->cntPipes)
                    msh->cntPipes = -1;
                msh->cmd[i + 1] = NULL;
            }
            else
                msh->cmd[i] = NULL;
            // execve("/bin/", msh->cmd, envp);
            printf("msh->cmd[%d]: %s\n", i, msh->cmd[i]);
            i = -1;
            printf("cntPipes: %d\n", msh->cntPipes);
            
        }
        token = token->next;
        i++;
    }
    msh->cmd[i + 1] = NULL;