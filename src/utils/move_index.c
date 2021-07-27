//
// Created by Cesar Erebus on 7/27/21.
//

void move_index(char *str, int *i, char c)
{
	while(str[*i] && str[*i] == c)
		(*i)++;
}