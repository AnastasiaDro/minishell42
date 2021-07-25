//
// Created by Cesar Erebus on 7/25/21.
//

#include <unistd.h>
#include <stdio.h>
#include "here_doc.h"
#include "../minishell.h"

//возвращает строку после гнл-а
int getHereDocFile(int i,  char *limiter)
{
	int tmpFd;

	tmpFd = getTmpFile(limiter);

}
