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



///1 добавила тут
///обработка ctrl_C
void ctrl_c(int num)
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
///конец изменений


///2 добавила тут
int ctrl_d(t_msh *msh)
{
    if (msh->line == NULL || !ft_strncmp("exit", msh->line, ft_strlen(msh->line)))
    {
        printf("exit\n");
        return (1);
    }
    return (0);
}
///конец изменений

 int main(int ac, char **av, char **env)
{
    t_msh msh;

    (void)ac;
    (void)av;
    (void)env;
///3 добавила тут
    signal(SIGINT, ctrl_c);
///конец изменений
     ft_memset(&msh, 0, sizeof(msh));
     msh.line = NULL;

    while (1)
    {
        msh.line = readline("msh: ");
    ///4 добавила тут
        if (ctrl_d(&msh))
            break;
    ///конец изменений
        msh.len = ft_strlen(msh.line);
        if (msh.len > 0)
        {
            add_history(msh.line);
            ft_parser(&msh);
        }
        free(msh.line);
        msh.line = NULL;
    }
    return (0);
}