cmake_minimum_required(VERSION 3.19)
project(msh_42 C)

set(CMAKE_C_STANDARD 99)

add_executable(msh_42 src/minishell.c src/parser.c src/errors.c src/init.c src/ft_exit.c src/ft_echo.c src/ft_pwd.c
src/ft_cd.c src/env_export_unset.c src/env_list.c src/exec.c src/here_doc/here_doc.c src/here_doc/here_doc.h src/here_doc/getTmpFile.c
        src/here_doc/getStdin.c src/here_doc/getExecArr.c src/here_doc/findPath.c src/here_doc/pipexSplit.c src/here_doc/printError.c
        src/here_doc/execArrSplit.c src/here_doc/findCommand.c src/here_doc/getBinaryName.c src/here_doc/getHereDocFile.c src/checkHereDoc.c src/execBinary.c src/here_doc/closeAllFds.c
        src/here_doc/bonusClean.c src/here_doc/mFree.c src/here_doc/checkFileFd.c src/here_doc/checkExecArr.c)

target_link_libraries(msh_42 "/Users/cerebus/CLionProjects/msh-42/libft/libft.a" -L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline)