#include "minishell.h"

int ctrl_d(t_msh *msh)
{
	if (msh->line == NULL || !ft_strcmp("exit", msh->line))
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

//ф-я стат должна выдать ноль, когда происходит совпадение

void ctrl_c(int num)
{
	if (num == SIGINT)
	{
		struct termios term;
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
	(void)ac;
	(void)av;
	(void)envp;
	signal(SIGINT, ctrl_c);
	ft_init(&msh, envp);
	while (1)
	{
		msh.line = readline("msh: ");
        if (ctrl_d(&msh))
        	break;
		msh.len = ft_strlen(msh.line);
		if (msh.len > 0)
		{
			add_history(msh.line);
			parser(&msh, msh.line);
			cerExec(&msh);
		}
		free(msh.line);
		msh.line = NULL;
	}
	return (0);
}