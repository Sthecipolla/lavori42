# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhima <lhima@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 16:17:56 by lhima             #+#    #+#              #
#    Updated: 2025/01/27 11:32:44 by lhima            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

OTHER_SOURCE = ./printf/libftprintf.a ./get_next_line/get_next_line.a


SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
	ft_strlcat.c ft_tolower.c ft_strchr.c ft_strrchr.c \
	ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c \
	ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_calloc.c ft_strdup.c ft_split.c \
	ft_toupper.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C printf
	@make -C get_next_line
	@ar rcs $(NAME) $(OBJ) $(OTHER_SOURCE)

clean:
	@make -C printf clean
	@make -C get_next_line clean
	@rm -f $(OBJ)

fclean: clean
	@make -C printf fclean
	@make -C get_next_line fclean
	@rm -f $(NAME)

re: fclean all
	@make -C printf re
	@make -C get_next_line re

.PHONY: all clean fclean re

.SILENT:
