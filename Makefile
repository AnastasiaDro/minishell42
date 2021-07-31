NAME = minishell

CER	 = cerebus

HOME = home

SRCS =	src/minishell.c src/parser.c src/errors.c src/init.c src/ft_exit.c src/ft_echo.c src/ft_pwd.c \
		src/env_export_unset.c src/env_list.c  src/ft_cd.c  src/handlers.c src/parse_command.c \
		src/utils/move_index.c src/exec_cer.c src/waitChildren.c src/getExportVar.c src/execBinary.c \
		src/findCommand.c src/pipexSplit.c src/printError.c src/getBinaryName.c src/closeAllFds.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -g

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@make bonus -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -ltermcap -L/Users/jkeitha/.brew/Cellar/readline/8.1/lib/ -I/Users/jkeitha/.brew/Cellar/readline/8.1/include -lreadline


$(CER):		$(OBJS)
			@make bonus -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline

$(HOME):	$(OBJS)
			@make bonus -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -ltermcap -L/usr/local/opt/readline/lib -I/usr/local/opt/readline/include -lreadline



run:		$(NAME)
			@./$(NAME)

clean:
			@$(RM) $(OBJS)
			@make clean -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY: 	all run clean fclean re