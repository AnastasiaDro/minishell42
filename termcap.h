//
// Created by Cesar Erebus on 6/6/21.
//

#ifndef TERMCAP_H
# define TERMCAP_H


char *arr_strchr(char *s, char c)
{
    char	*str;

    str = (char *)s;
    if (c == '\0')
        return (&str[ft_strlen(str)]);
    while (*str)
    {
        if (*str == c)
            return (str);
        str++;
    }
    return (NULL);
}

#endif //MINISHELL42_TERMCAP_H
