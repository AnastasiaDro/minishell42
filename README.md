
TODO: bugs
	-cd done(jkeitha)
	-$: done(cerebus)
TODO: Dublicates
	-getValue() & getExportVar()
TODO: norminette
	-src/ft_cd.c: OK!(fix: segFault then unset HOME, keys: cd work)
	-src/ft_echo.c: OK!
	-src/ft_exit.c: OK!
	-src/ft_pwd.c: OK!
	-src/parser.c: OK!
	-src/parser.c: OK!
	-src/initFds.c: OK!
	-src/exec_cer.c: before func cerExec() norm and work





void inQuotes(char **line)
{
    char sym;

    sym = **line;
    ++*line;
    while (*line && **line && **line != sym)
        ++*line;
    if (**line == '\0')
        ft_error(1, "MULTILINE_NOT_SUPPORTED");
    else
        ++*line;
}