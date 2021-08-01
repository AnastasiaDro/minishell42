#include "minishell.h"
#include "env_export_unset.h"

int execBuiltin(t_msh *msh)
{
    int i;

    i = 0;

    if (!ft_strncmp(msh->cmd[i], "echo", 4))
    {
        ft_echo(msh->cmd);
        return (1);
    }
    if (!ft_strncmp(msh->cmd[i], "pwd", ft_strlen(msh->cmd[i])))
    {
        ft_pwd();
        return (1);
    }
    if (!ft_strncmp(msh->cmd[i], "env", 3))
    {
        ft_print_env(msh);
        printf("печатает лист\n");
        return (1);
    }
    if (!ft_strcmp(msh->cmd[i], "cd"))
    {
        ft_cd(msh, "cd ..");
        return (1);
    }
    if (!ft_strcmp(msh->cmd[i], "export"))
    {
        if (msh->cmd[i + 1] != NULL)
        {
            exportHandler(msh, i);
        }
        ft_print_export(msh);
        return (1);
    }
    if (!strncmp(msh->cmd[i], "unset", ft_strlen(msh->cmd[i])))
    {
        if (msh->cmd[i + 1] != NULL)
            ft_unset(msh, &(msh->cmd[i + 1]));
        return (1);
    }
    return (0);
}

// void dollarSign(t_msh *msh)
// {
//     int i;
//     int errNo = 0; //TODO: временно добавил

//     i = 0;
//     if (!ft_strncmp(msh->cmd[i], "$", 1))
//     {
//         if (!ft_strncmp(msh->cmd[++i], "?", 1))
//         {
//             ft_putnbr_fd(errNo, 1);
//             ft_putendl_fd(": command not found", 1);
//         }
//     }
// }

void exec(t_msh *msh)
{
    int i;
    int j; //индекс для прохода по строке
	char **cmdArr;

    i = -1;

	//parse_command(msh, 0);

    while (msh->cmd[++i])
    {
		t_cmd *cmd_s = malloc(sizeof (t_cmd));
    	cmd_s->com_num = i;
		cmd_s->cmdTokens = lexer_again(msh->cmd[i]); //засовываем в лексер команду
    	//и получаем массив токенов команды
    	j = -1;
       while(cmd_s->cmdTokens[++j]) //пока у нас есть токены
	   {
       		//чекаем управляющие символы
		   check_ctrl_symbol(cmd_s, &j);
		   //чекаем билдины
		   
			//чекаем и/или выполняем бинарники
	   }
    }
}