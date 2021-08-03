cmake_minimum_required(VERSION 3.19)
project(msh_42 C)

set(CMAKE_C_STANDARD 99)

add_executable(msh_42 src/minishell.c src/parser.c src/errors.c src/init.c src/ft_exit.c src/ft_echo.c src/ft_pwd.c
        src/ft_cd.c src/enviroment/env_export_unset.c src/enviroment/envList.c src/exec.c
        src/execArrSplit.c
        src/parse_command.c src/utils/move_index.c
        src/getTmpFile.c src/utils/msh_utils.h src/get_fdIn.c src/setCommandFromStr.c src/pipexSplit.c
       src/new_s_com.c src/handlers.c src/parse_command.c src/exec_cer.c src/waitChildren.c src/getCommandArr.c src/getExportVar.c src/execBinary.c src/getBinaryName.c
        src/findCommand.c src/printError.c src/closeAllFds.c src/initFds.c src/utils/ft_lstFree.c src/freeMsh.c
        src/utils/ft_freeEnList.c src/utils/ft_freeStringsArr.c src/enviroment/envSetNameVal.c src/enviroment/envParsedLstNew.c src/dollar.c src/enviroment/unset.c)

target_link_libraries(msh_42 "/Users/cerebus/CLionProjects/msh-42/libft/libft.a" -L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline)