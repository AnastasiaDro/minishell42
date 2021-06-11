#include <sys/termios.h>
#include <term.h>
#include "minishell.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

void ft_parser(t_msh *msh)
{
    int i = 0;
    // char *token = NULL;
    // printf("before msh->line: %s\n", msh->line);
    // printf("befire msh->len: %d\n", msh->len);
    // token = ft_strsep(&msh->line, " ");
    while (msh->line[i] != '\0')
    {
        printf("char: |%c|\n", msh->line[i]);
        if (msh->line[i] == '\"')
        {
            int j = 0;
            if (msh->line[j] == '\"')

                j++;
        }
        i++;
    }
    // printf("after msh->line: %s\n", msh->line);
    // printf("after msh->len: %d\n", msh->len);
}




void ft_prompt(void)
{
	write(1, "msh:", 4);
}


///обработка ctrl_C
void cntrl_c(int num)
{
    if(num == SIGINT)
    {
        //write(1, "\n", 1);
        rl_redisplay();
        //ft_prompt();
        signal(SIGINT, cntrl_c);
    }

}


 int main(int ac, char **av, char **env)
{

    ///
    struct termios term;
    char *term_name;

    term_name = "xterm-256color";

    ///Нужно проверить все эти функции на возвращаемое значение!!!
    tcgetattr(0, &term);
    //term.c_lflag &= ~(ECHO);
   term.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &term);

    tgetent(0, term_name); //для термкапа отправляем
    ///

    t_msh msh;
    char *tmp;
    ft_memset(&msh, 0, sizeof(msh));
    msh.line = NULL;
    (void)ac;
    (void)av;
    (void)env;

    signal(SIGINT, cntrl_c);

    while (1)
    {

        msh.line = readline("msh: ");
        msh.len = ft_strlen(msh.line);
        if (msh.len > 0)
        {
            add_history(msh.line);
            ft_parser(&msh);
        }
        tmp = msh.line;
        msh.line = NULL;
        free(tmp);
        tmp = NULL;
        signal(SIGINT, cntrl_c);
    }
    free(msh.line);
    return (0);
	return (0);
}