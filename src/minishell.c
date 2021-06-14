#include <sys/termios.h>
#include <term.h>
#include "minishell.h"
#include "../libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <errno.h>

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
	write(1, "\nmsh: ", 5);
}


///обработка ctrl_C
void cntrl_c(int num)
{
    if(num == SIGINT)
    {
        //структура, куда сохраним настройки терминала, самому делать не надо, она из библиотеки #include <sys/termios.h>
        struct termios term;
       // char *term_name;

    //    term_name = "xterm-256color";

        ///Нужно проверить все эти функции на возвращаемое значение!!!
//        //получаем атрибуты терминала
        tcgetattr(0, &term);
//        //выключаем чета-там, что символ не отображается
        term.c_lflag &= ~(ECHO);
        term.c_lflag &= ~(ICANON);
//
//        //сетим атрибуты
        tcsetattr(0, TCSANOW, &term);

        //снвоа берем атрибуты
        tcgetattr(0, &term);
        //хардкодом включаем обратно как было (узнала число, сделав принтф перед изменением настроек printf(" %lx\n", term.cl_flag);
       term.c_lflag = 0x2020010d;
        //снова засетила атрибуты
        tcsetattr(0, TCSANOW, &term);
        //дальше уже знакомый код
        rl_replace_line("", 0);
        write(1, "\n", 1);
        rl_on_new_line();
        rl_redisplay();
        errno = 1;
    }
}



 int main(int ac, char **av, char **env)
{

  //  struct termios term;
    ///Нужно проверить все эти функции на возвращаемое значение!!!
    //получаем атрибуты терминала
//    tcgetattr(0, &term);
//    //выключаем чета-там, что символ не отображается
//    term.c_lflag &= ~(ICANON);
//    tcsetattr(0, TCSANOW, &term);

//    struct termios term;
//    char *term_name;
//
//    term_name = "xterm-256color";
//
//    ///Нужно проверить все эти функции на возвращаемое значение!!!
//    tcgetattr(0, &term);
//  term.c_lflag &= ~(ECHO);
// term.c_lflag &= ~(ICANON);
//
//    tcsetattr(0, TCSANOW, &term);
//    tgetent(0, term_name); //для термкапа отправляем
//    ///

    t_msh msh;
   // char *tmp;
    (void)ac;
    (void)av;
    (void)env;
  signal(SIGINT, cntrl_c);

     ft_memset(&msh, 0, sizeof(msh));
     msh.line = NULL;

    while (1)
    {
        msh.line = readline("msh: ");
        if (msh.line == NULL || !ft_strncmp("exit", msh.line, 8))
        {
            printf("exit\n");
            break;
        }

        msh.len = ft_strlen(msh.line);
        if (msh.len > 0)
        {
            add_history(msh.line);
            ft_parser(&msh);
        }
        free(msh.line);
        msh.line = "NULL";
    }
    return (0);
}