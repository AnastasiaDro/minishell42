NAME = minishell

SRCS = src/minishell.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -rf

CFLAGS = -g3 -Wall -Wextra -Werror

all:		$(NAME)

%.o: %.c
			$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME): 	$(OBJS)
			@make -C libft
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libft/libft.a
	
run:		$(NAME)
			./$(NAME)

clean:
			$(RM) $(OBJS)
			@make clean -C libft

fclean:		clean
			@$(RM) $(NAME)
			@make fclean -C libft

re:
			fclean all

.PHONY: 	all run clean fclean re