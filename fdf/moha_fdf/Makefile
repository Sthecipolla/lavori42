SRCS = \
fdf.c \
parsing.c \
bresenham.c \
close.c \
utils.c \
draw.c \
utils_draw.c \

NAME =		fdf
CFLAGS =	 -g

all:		$(NAME)

$(NAME):	libft/libft.a minilibx-linux/libmlx.a $(SRCS)
			gcc $(CFLAGS) $(SRCS) libft/libft.a -Lminilibx-linux -lmlx -lXext -lX11 -lm -o $(NAME) -O3

libft/libft.a:
			make -C libft

minilibx-linux/libmlx.a:
			if [ ! -d "minilibx-linux" ]; then \
				git clone https://github.com/42Paris/minilibx-linux.git; \
			fi
			make -C minilibx-linux

clean:
			rm -f *.o
			make -C libft clean
fclean: clean
			rm -f $(NAME)
			rm -f minilibx-linux/libmlx_Linux.a
			rm -f minilibx-linux/libmlx.a
			make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
