#include <stdio.h>
#include <libc.h>
#include "libft/libft.h"



int sort(char **arr, t_list **list)
{
    int i;
    t_list *tmp;
    t_list *l_p;

    i = 0;
    *list = ft_lstnew(arr[0]);
    l_p = *list;
    while (arr[i])
    {
        l_p = *list;
        while (1)
        {
            if (l_p->next == NULL || strcmp(arr[i], l_p->next->content) < 0)
            {
                tmp = l_p->next;
                l_p->next = ft_lstnew(arr[i]);
                l_p->next->next = tmp;
                break;
            }
            else
                l_p++;
        }
        i++;
    }
    return (i);
}


int main()
{
    char **arr = calloc(sizeof(char *), 20);
    arr[0] = "declare -x SHLVL=2";
    arr[1] = "declare -x OLDPWD";
    arr[2] = "declare -x HOME=/Users/anastasia";
    arr[3] = "declare -x LC_CTYPE=UTF-8";
    arr[4] = "declare -x LOGNAME=anastasia";
    arr[5] ="declare -x SSH_AUTH_SOCK=/private/tmp/com.apple.launchd.x8IKTbdgJc/Listeners";
    arr[6] = "declare -x PATH=/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:/Library/Apple/usr/bin";
    arr[7] = "declare -x PWD=/Users/anastasia/CLionProjects/minishell42";
    arr[8] = "declare -x SHELL=/bin/bash";
    arr[9] = "declare -x TERM=xterm-256color";
    arr[10] = NULL;

    t_list *list = malloc(sizeof(t_list) * 1);
    int res = sort(arr, &list);
    while (list->content)
    {
        printf("строка s = %s\n", (char *)list->content);
        list++;
    }
    



    printf(" res = %d\n", res);

// declare -x TERM_PROGRAM="Apple_Terminal"
// declare -x TERM_PROGRAM_VERSION="440"
// declare -x TERM_SESSION_ID="75335195-9069-4A0C-87C2-C2758C433612"
// declare -x TMPDIR="/var/folders/85/y8f0507d2pggnf8910_xnynw0000gn/T/"
// declare -x USER="anastasia"
// declare -x XPC_FLAGS="0x0"
// declare -x XPC_SERVICE_NAME="0"
// declare -x _="/bin/bash"
// declare -x __CFBundleIdentifier="com.apple.Terminal";
}