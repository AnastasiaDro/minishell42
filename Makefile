NAME = minishell

SRCS =	src/minishell.c src/parser.c src/errors.c src/init.c src/ft_exit.c src/ft_echo.c src/ft_pwd.c src/ft_cd.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

all:		$(NAME)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
	@make bonus -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a -ltermcap -L/Users/jkeitha/.brew/Cellar/readline/8.1/lib/ -I/Users/jkeitha/.brew/Cellar/readline/8.1/include -lreadline
	
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