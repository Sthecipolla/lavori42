NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

MINILBX = -Lminilibx-linux -lmlx -lXext -lX11 -Llibft -l:libft.a -Lprintf -l:libftprintf.a -Lget_next_line -l:get_next_line.a

SRC = main.c map.c check_border.c check_portal.c check_player.c check_coins.c so_long_utils.c check_utils.c\
input_menag.c img_print.c error.c


all: $(NAME)

$(NAME): $(SRC)
	@make -C get_next_line
	@make -C libft
	@make -C printf
	$(CC) $(SRC) $(CFLAGS) $(MINILBX) -o lets_go

clean:
	@make clean -C get_next_line
	@make clean -C libft
	@make clean -C printf

fclean: clean
	@make fclean -C get_next_line
	@make fclean -C libft
	@make fclean -C printf
	@rm -f $(NAME)

re: fclean all
	@make re -C get_next_line
	@make re -C libft
	@make re -C printf

#da commentare dopo
norminette_all:
	norminette ./libft ./get_next_line ./printf $(SRC)

norminette:
	norminette $(SRC)

go:
	make && clear && valgrind -s --leak-check=full --track-origins=yes --show-reachable=yes ./lets_go
#
.PHONY: all clean fclean re
