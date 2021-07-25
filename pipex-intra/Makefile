NAME	=	pipex
MAIN	= 	main.c
SRC		=	execArrSplit.c findCommand.c findPath.c getBinaryName.c getExecArr.c \
			pipexSplit.c printError.c waitChildren.c simpleFirstCommand.c simpleLastCommand.c\
			mFree.c simpleCloseFds.c simpleCheckFileFd.c simpleCheckExecArr.c
BONUS	= 	bonusMain.c bonusParseCmd.c bonusFirstCommand.c bonusLastCommand.c bonusParseMiddleCommands.c \
			get_next_line/get_next_line.c get_next_line/get_next_line_utils.c get_next_line/gnl_wrap_utils.c\
			bonusCheckHereDoc.c bonusGetStdin.c bonusGetTmpFile.c bonusParseHereDoc.c\
			bonusParsePipesOnly.c bonusParseLastRedirect.c checkFileFd.c initStruct.c\
			bonusClean.c closeAllFds.c checkExecArr.c
CFLAGS	= 	-Wall -Wextra -Werror
LIBFT	= 	libft/libft.a
OMAIN	= 	$(MAIN:.c=.o)
OBJS	= 	$(SRC:.c=.o)
BOBJS 	= 	$(BONUS:.c=.o)

%.o: %.c
			@$(CC) $(CFLAGS) -c -I./libft/ $< -o $(<:.c=.o)

$(NAME):	$(OMAIN) $(OBJS)
			@make bonus -C libft
			@gcc $(OBJS) $(OMAIN) $(LIBFT) -o $(NAME)


all:		$(NAME)

bonus:		$(OBJS) $(BOBJS)
			@make bonus -C libft
			@gcc $(OBJS) $(BOBJS) $(LIBFT) -o $(NAME)

clean:
			@rm -f $(OBJS)
			@rm -f $(BOBJS)
			@rm -f $(OMAIN)
			@make bfclean -C libft

fclean:		clean
			@rm -f $(NAME)
			@make bfclean -C libft

re:			fclean all

.PHONY:		all clean fclean re bonus
