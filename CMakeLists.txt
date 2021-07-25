cmake_minimum_required(VERSION 3.19)
project(msh_42 C)

set(CMAKE_C_STANDARD 99)

add_executable(msh_42 src/minishell.c src/parser.c src/errors.c src/init.c src/ft_exit.c src/ft_echo.c src/ft_pwd.c
src/ft_cd.c src/env_export_unset.c src/env_list.c src/exec.c)

target_link_libraries(msh_42 "/Users/cerebus/CLionProjects/msh-42/libft/libft.a" -L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline)