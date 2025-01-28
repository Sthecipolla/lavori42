NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

SRC = check.c swap.c swap_a.c push_swap_utils.c error_men.c

all: $(NAME)
	clear


$(NAME): $(SRC)
	@make -C ./libft
	@make -C ./printf
	$(CC) $(CFLAGS) $(SRC) $(OTHER_SOURCE) -o $(NAME)

checker:
	wget https://cdn.intra.42.fr/document/document/28256/checker_linux

delete_checker:
	rm -f checker_linux
#
norminette:
	norminette $(SRC) push_swap.h

norminette_all:
	norminette $(SRC) ./libft/

#go:
# da cancellare
clean:
	@make -C ./libft clean
	@make -C ./printf clean
	clear

fclean: clean
	@make -C ./libft fclean
	@make -C ./printf fclean
	rm -f $(NAME)
	clear

re: fclean all
	@make -C ./libft re
	@make -C ./printf re
	clear

.PHONY: all clean fclean re
