#ifndef MINISHELL_H
#define MINISHELL_H

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct s_msh // main struct
{
	int fd;
}t_msh;

#endif