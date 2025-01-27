NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OTHER_SOURCE = -L./libft -l:libft.a

SRC = check.c swap.c

all: $(NAME)


$(NAME): $(SRC)
	@make -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(OTHER_SOURCE) -o $(NAME)
#
norminette:
	norminette $(SRC) push_swap.h

norminette_all:
	norminette $(SRC) ./libft/

#go:
# da cancellare
clean:
	@make -C clean ./libft

fclean: clean
	@make -C fclean ./libft
	rm -f $(NAME)

re: fclean all
	@make -C re ./libft

.PHONY: all clean fclean re
