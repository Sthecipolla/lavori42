NAME = so_long.a

CC = cc

MAKEFILENUM1 = minilibx_opengl/minilibx_opengl_20191021/Makefile

MAKEFILENUM2 = minilibx_mms_20200219_beta/minilibx_mms_20200219/Makefile

CFLAGS = -Wall -Wextra -Werror -g

SRC = main.c

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
