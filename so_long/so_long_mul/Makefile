NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MINILBX = -Lminilibx-linux -lmlx -lXext -lX11 -Llibft -l:libft.a -Lprintf -l:libftprintf.a -Lget_next_line -l:get_next_line.a

SRC = main.c map.c check_border.c check_portal.c check_player.c check_coins.c so_long_utils.c check_utils.c\
input_menag.c img_print.c error.c

MINILB = ./minilibx-linux/

MAKEFILE = -s

all: $(MINILB) $(NAME)

$(NAME): $(SRC)
	@make -C get_next_line
	@make -C libft
	@make -C printf
	@$(CC) $(SRC) $(CFLAGS) $(MINILBX) -o so_long

$(MINILB):
	wget https://cdn.intra.42.fr/document/document/31497/minilibx-linux.tgz
	tar -xvf minilibx-linux.tgz
	make -C minilibx-linux
	rm -f minilibx-linux.tgz

clean:
	@make clean -C get_next_line
	@make clean -C libft
	@make clean -C printf

fclean: clean
	@make fclean -C get_next_line
	@make fclean -C libft
	@make fclean -C printf
	@rm -rf ./minilibx-linux/
	@rm -f $(NAME)

re: fclean all
	@make re -C get_next_line
	@make re -C libft
	@make re -C printf

.PHONY: all clean fclean re

.SILENT:
