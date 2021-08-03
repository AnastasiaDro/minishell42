/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 17:09:15 by jkeitha           #+#    #+#             */
/*   Updated: 2021/08/03 17:09:17 by jkeitha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ctrl_d(t_msh *msh)
{
	if (msh->line == NULL || !ft_strcmp("exit", msh->line))
	{
		printf("exit\n");
		return (1);
	}
	return (0);
}

void	ctrl_c(int num)
{
	struct termios	term;

	if (num == SIGINT)
	{
		tcgetattr(0, &term);
		term.c_lflag &= ~(ECHO);
		term.c_lflag &= ~(ICANON);
		tcsetattr(0, TCSANOW, &term);
		tcgetattr(0, &term);
		term.c_lflag = 0x2020010d;
		tcsetattr(0, TCSANOW, &term);
		rl_replace_line("", 0);
		write(1, "\n", 1);
		rl_on_new_line();
		rl_redisplay();
		errno = 1;
	}
}

int	main(int ac, char **av, char **envp)
{
	t_msh	msh;

	(void)ac;
	(void)av;
	(void)envp;
	signal(SIGINT, ctrl_c);
	ft_init(&msh, envp);
	while (1)
	{
		msh.line = readline("msh: ");
		if (ctrl_d(&msh))
			break ;
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
