NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

BONUSFOLDER = checker/

BONUS = $(BONUSFOLDER)main_checker.c $(BONUSFOLDER)move.c

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a -Lget_next_line -l:get_next_line.a

SRC = main.c sort_check.c rotate.c check_if_valid_num.c swap.c \
push_swap_utils.c error_men.c push.c reverse.c atoi_but_long.c \
fill_function.c sort_four.c utils_sorting.c sort_three.c sort_five.c \
sort_num.c sort_utils_for_num.c sort_utils_for_num_second.c

APP = app

OBJ_DIR_BONUS = obj_bonus

OBJ_BONUS = $(BONUS:%.c=%.o)


OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	clear

bonus: $(OBJ) $(OBJ_BONUS)
	@make -C ./libft
	@make -C ./printf
	@make -C ./get_next_line
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(OBJ) $(OTHER_SOURCE) -o checkers

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@make -C ./get_next_line
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@


norminette:
	norminette $(SRC) push_swap.h

norminette_all:
	norminette $(SRC) ./libft/
	norminette $(SRC) ./printf/

clean:
	@make -C ./libft clean
	@make -C ./printf clean
	@make -C ./get_next_line clean
	rm -f $(OBJ)
	rm -r obj
	clear

fclean: clean
	@make -C ./libft fclean
	@make -C ./printf fclean
	@make -C ./get_next_line fclean
	rm -f $(NAME)
	clear

re: fclean all
	@make -C ./libft re
	@make -C ./printf re
	@make -C ./get_next_line re
	clear

.PHONY: all clean fclean re
