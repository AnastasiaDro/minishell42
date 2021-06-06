#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include "libft/libft.h"
#include "termcap.h"

int main()
{
    char str[2000];
    int read_bytes;
    struct termios term;

    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHO);
    term.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &term);
    while(!ft_strchr(str,'\n')) //в оригинале функция работает с константными строками
    {
        read_bytes = read(0, str, 100);
        write(1, str, read_bytes);
    }
    write(1, "\n", 1);
	printf("Hello, World!\n");
	return 0;
}
