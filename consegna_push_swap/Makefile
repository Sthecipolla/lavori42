NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

SRC = main.c sort_check.c rotate.c check_if_valid_num.c swap.c \
push_swap_utils.c error_men.c push.c reverse.c atoi_but_long.c \
fill_function.c sort_four.c utils_sorting.c sort_three.c sort_five.c \
sort_num.c sort_utils_for_num.c sort_utils_for_num_second.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

clean:
	@make -C ./libft clean
	@make -C ./printf clean
	@rm -f $(OBJ)

fclean: clean
	@make -C ./libft fclean
	@make -C ./printf fclean
	@rm -f $(NAME)

re: fclean all
	@make -C ./libft re
	@make -C ./printf re

.PHONY: all clean fclean re
