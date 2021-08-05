cmake_minimum_required(VERSION 3.19)
project(msh_42 C)

set(CMAKE_C_STANDARD 99)

file(GLOB helloworld_SRC
        "*.h"
        "src/*.c"
        "src/enviroment/*.c"
        "src/utils/*.c"
        )
file(GLOB msh_SRC
        "*.h"
        "src/*.c"
        "src/enviroment/*.c"
        "src/utils/*.c"
        )



add_executable(msh_42 ${msh_SRC} src/parseHereDoc.c src/checkControlSymbol.c)

target_link_libraries(msh_42 "/Users/cerebus/CLionProjects/msh-42/libft/libft.a" -L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline)