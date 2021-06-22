#include "minishell.h"
#include "env_export_unset.h"



int ctrl_d(t_msh *msh)
{
	if (msh->line == NULL || !ft_strncmp("exit", msh->line, ft_strlen(msh->line)))
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

void ctrl_c(int num)
{
	if (num == SIGINT)
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

int main(int ac, char **av, char **envp)
{

    printf("strncmp %d\n", ft_strncmp("A", "B", 2));

	t_msh msh;
	(void)ac;
	(void)av;
	(void)envp;
	signal(SIGINT, ctrl_c);

    //ft_init(&msh);
//	ft_memset(&msh, 0, sizeof(msh));
	ft_init(&msh, envp);
    //ft_env(envp);
	while (1)
	{
		msh.line = readline("msh: ");
		if (ctrl_d(&msh))
            break;
		msh.len = ft_strlen(msh.line);
		printf("msh.line = %s\n", msh.line);

		//новое
		if (!ft_strncmp("export", msh.line, 6))
			ft_print_export(&msh);

		if (msh.len > 0)
		{
			add_history(msh.line);
			ft_parser(&msh);
		}

		//тест

		free(msh.line);
		msh.line = NULL;
	}
	return (0);
}