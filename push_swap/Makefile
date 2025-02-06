NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

N = 3 12 14 90 21 554

SRC = main.c sort_check.c rotate.c check_if_valid_num.c swap.c \
push_swap_utils.c error_men.c push.c reverse.c atoi_but_long.c \
fill_function.c sort_four.c utils_sorting.c sort_three.c sort_five.c \
sort_num.c sort_utils_for_num.c

APP = app

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	clear

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

checker:
	wget https://cdn.intra.42.fr/document/document/28256/checker_linux


delete_checker:
	rm -f checker_linux
#
$(APP):
	if [ -f move.txt ]; then rm -f move.txt; fi
	if [ -f error.txt ]; then rm -f error.txt; fi

remove: $(APP)

norminette:
	norminette $(SRC) push_swap.h

norminette_all:
	norminette $(SRC) ./libft/
	norminette $(SRC) ./printf/

rapid_test:
	./push_swap $(LISTNUM) 2> error.txt
#go:

go_with_count:
	./push_swap $(N) | tee move.txt | grep '[a-zA-Z]' | wc -l
# da cancellare ce da canellare un po di roba sotto che e stata messa in piu
clean:
	@make -C ./libft clean
	@make -C ./printf clean
	rm -f $(OBJ)
	rm -r obj
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
