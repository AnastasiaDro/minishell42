NAME = minishell

SRCS =	src/minishell.c src/parse.c \
		# src/ft_echo.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -g

all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@make -C libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
	
run:		$(NAME)
			@./$(NAME)

clean:
			$(RM) $(OBJS)
			@make clean -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C libft

re:			fclean all

.PHONY: 	all run clean fclean re