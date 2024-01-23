# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpapa <kpapa@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/19 18:07:00 by kpapa             #+#    #+#              #
#    Updated: 2023/03/22 20:04:57 by kpapa            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

LIBFT_PATH	=	./libft
LIBFT	=	$(LIBFT_PATH)/libft.a

CC	=	clang
CFLAGS	=	-Wall -Wextra -Werror

RM	=	rm -f

AR	=	ar
ARFLAGS	=	rcs

SOURCES	= ft_print_csp.c ft_print_idux.c ft_printf.c

OBJECTS	=	$(SOURCES:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(LIBFT_PATH)

all:	$(LIBFT) $(NAME)

$(LIBFT):
		make -C $(LIBFT_PATH)

$(NAME):	$(OBJECTS)
			cp $(LIBFT) $(NAME)
			$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJECTS)

fclean:	clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re libft
