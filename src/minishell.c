#include "minishell.h"

int ctrl_d(char *line)
{
	if (line == NULL || !ft_strncmp("exit", line, ft_strlen(line)))
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
	t_msh msh;
	char *line;
	(void)ac;
	(void)av;
	(void)envp;
	signal(SIGINT, ctrl_c);
	ft_init(&msh);
	ft_memset(&msh, 0, sizeof(msh));
	while (1)
	{
		line = readline("msh: ");
		msh.len = ft_strlen(line);
		if (msh.len > 0)
		{
			add_history(line);
			ft_parser(&msh, line);
		}
		free(line);
		line = NULL;
	}
	return (0);
}