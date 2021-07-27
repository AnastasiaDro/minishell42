//
// Created by Cesar Erebus on 7/27/21.
//

#include "minishell.h"

t_cmd *new_s_command()
{
	t_cmd *n_s_com;

	n_s_com = malloc(1 * sizeof (t_cmd));
	n_s_com->red_small_fd = -2;
	n_s_com->red_smal = 0;
	return (n_s_com);
}