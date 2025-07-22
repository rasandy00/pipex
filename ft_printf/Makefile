# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 13:02:01 by andriamr          #+#    #+#              #
#    Updated: 2025/05/27 13:19:27 by andriamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c \
		ft_putchar_printf.c \
		ft_putnbr_printf.c \
		ft_putstr_printf.c \
		hex_printf.c \
		
CC = gcc

FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c 
	$(CC) $(FLAG) -o $@ -c $<

$(NAME) : $(OBJ)
	-ar rsc -o $(NAME) $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re