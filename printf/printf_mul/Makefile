# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhima <lhima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 14:55:29 by lhima             #+#    #+#              #
#    Updated: 2024/12/10 10:34:41 by lhima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc 

CFLAGS = -Wall -Wextra -Werror -g

SRC = ft_printf.c ft_putnumbase.c ft_addresspointer.c ft_putnbre_fd.c ft_putstra_fd.c ft_putchare_fd.c ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(SRC)

	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re