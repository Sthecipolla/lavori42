NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MINILBX = -Lminilibx-linux -lmlx -lXext -lX11 #-Llibft -Lprintf

#LIB =
SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(MINILBX) -o lets_go

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

#da commentare dopo
norminette:
	norminette ./libft ./get_next_line ./so_long

.PHONY: all clean fclean re
