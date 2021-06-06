#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <term.h>
#include "libft/libft.h"

int main()
{
    char str[2000];
    int read_bytes;
    struct termios term;
    char *term_name;

    term_name = "xterm-256color";

    ///Нужно проверить все эти функции на возвращаемое значение!!!
    tcgetattr(0, &term);
    term.c_lflag &= ~(ECHO);
    term.c_lflag &= ~(ICANON);
    tcsetattr(0, TCSANOW, &term);

    tgetent(0, term_name); //для термкапа отправляем

    while(!ft_strchr(str,'\n')) //в оригинале функция работает с константными строками
    {
        read_bytes = read(0, str, 100);
        write(1, str, read_bytes);   //если печатать escape-последовательности обычным write-ом, то терминал их фоспринимает
                                        //как движение каретки
    }
    write(1, "\n", 1);
	return 0;
}
