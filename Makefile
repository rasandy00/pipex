# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andriamr <andriamr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 16:43:03 by andriamr          #+#    #+#              #
#    Updated: 2025/07/28 08:56:06 by andriamr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = 	LIBFT/libft.a \
			ft_printf/ft_printf.a \

SRC =	main.c \
		take_path.c \
		acces.c \
		
		
CC = cc

LIBFT = LIBFT/libft.a

PRINTF  = ft_printf/libftprintf.a

MAKELIB = make -C LIBFT/

MAKEPRINTF = make -C ft_printf/

FLAG = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = pipex

all : $(NAME)

%.o : %.c
	$(CC) $(FLAG) -o $@ -c $<

$(NAME) : $(OBJ)
	$(MAKELIB)
	$(MAKEPRINTF)
	$(CC) -g $(FLAG) $(OBJ) $(PRINTF) $(LIBFT) -o $(NAME)

clean :
	$(MAKEPRINTF) clean
	$(MAKELIB) clean
	rm -f $(OBJ)

fclean : clean
	$(MAKELIB) fclean
	$(MAKEPRINTF) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
	