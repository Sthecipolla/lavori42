NAME = push_swap

NAME_CHECKER= checker

BONUSFOLDER = the_checker/

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a -L./get_next_line -l:get_next_line.a

OTHER_FILE = sort_check.c rotate.c check_if_valid_num.c swap.c \
		push_swap_utils.c error_men.c push.c reverse.c atoi_but_long.c \
		fill_function.c utils_sorting.c sort_three.c \
		sort_num.c sort_utils_for_num.c sort_utils_for_num_second.c

BONUS = $(BONUSFOLDER)main_bonus.c $(BONUSFOLDER)move_bonus.c $(OTHER_FILE) \
		$(BONUSFOLDER)swap_bonus.c $(BONUSFOLDER)rotate_bonus.c $(BONUSFOLDER)push_bonus.c \
		$(BONUSFOLDER)reverse_bonus.c

SRC = main.c $(OTHER_FILE)

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@make -C ./get_next_line
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_BONUS)
	@make -C ./libft
	@make -C ./printf
	@make -C ./get_next_line
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(OTHER_SOURCE) -o $(NAME_CHECKER)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft clean
	@make -C ./printf clean
	@make -C ./get_next_line clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./printf fclean
	@make -C ./get_next_line fclean
	@rm -f $(NAME)
	@rm -f $(NAME_CHECKER)

re: fclean all
	@make -C ./libft re
	@make -C ./printf re
	@make -C ./get_next_line re

rebonus: fclean bonus
	@make -C ./libft re
	@make -C ./printf re
	@make -C ./get_next_line re

.PHONY: all clean fclean re bonus rebonus 
