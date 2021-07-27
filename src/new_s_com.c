//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"

t_command *new_s_command()
{
	t_command *n_s_com;

	n_s_com = malloc(1 * sizeof (t_command));
	n_s_com->red_small_fd = -2;
	n_s_com->red_smal = 0;
	return (n_s_com);
}