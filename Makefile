NAME = minishell

CER	 = cerebus

HOME = home

SRCS =	src/environment/envAddNew.c \
		src/environment/envDeleteVar.c \
		src/environment/envInitEnvpList.c \
		src/environment/envParsedLstNew.c \
		src/environment/envPrintLists.c \
		src/environment/envSetNameVal.c \
		src/environment/envUnset.c \
		src/environment/environment.c \
		src/utils/ft_freeStringsArr.c \
		src/utils/ft_lstFree.c \
		src/utils/move_index.c \
		src/checkControlSymbol.c \
		src/closeAllFds.c \
		src/dollar.c \
		src/execArrSplit.c \
		src/execBinary.c \
		src/exec_cer.c \
		src/exportHandler.c \
		src/findCommand.c \
		src/ft_cd.c \
		src/ft_echo.c \
		src/ft_exit.c \
		src/ft_pwd.c \
		src/getBinaryName.c \
		src/getExportVar.c \
		src/hasTokens.c \
		src/init.c \
		src/initFds.c \
		src/lexer.c \
		src/minishell.c \
		src/parseHereDoc.c \
		src/parseRedirects.c \
		src/parser.c \
		src/pipexSplit.c \
		src/printError.c \
		src/waitChildren.c 

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


$(CER):		$(OBJS)
			@make bonus -C libft
			@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) ./libftCer/libft.a -L/Users/cerebus/.brew/Cellar/readline/8.1/lib/ -I/Users/cerebus/.brew/Cellar/readline/8.1/include -lreadline

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