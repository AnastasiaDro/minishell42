# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkeitha <jkeitha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 11:22:16 by cerebus           #+#    #+#              #
#    Updated: 2021/08/05 23:00:55 by jkeitha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
FLAGS	=	-Wall -Wextra -Werror
HEADER	=	libft.h
SRC		=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
			ft_isprint.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c ft_strlcpy.c\
			ft_strlen.c ft_strncmp.c ft_strrchr.c ft_tolower.c ft_strnstr.c\
			ft_toupper.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c\
			ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c
BONUS	= 	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c\
			ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\
			bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c\
			get_next_line/gnl_wrap_utils.c ft_arrlen.c ft_strcspn.c ft_strsep.c

CC		=	gcc
OBJS	=	$(SRC:.c=.o)
BOBJS	=	$(BONUS:.c=.o)

.c.o:
			@$(CC) $(FLAGS) -g -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rc libft.a $(OBJS)

all:		$(NAME)

clean:
			@rm -f $(OBJS)

fclean:		clean bfclean
			@rm -f $(NAME)

re:			fclean all

bonus:		$(OBJS) $(BOBJS)
			@ar rc libft.a $(OBJS) $(BOBJS)

bfclean:
			@rm -f $(BOBJS)


.PHONY:		all clean fclean re bonus bfclean
