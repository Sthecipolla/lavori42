NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c main.c command.c

BONUS = pipex_bonus.c main_bonus.c command_bonus.c

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

OBJ = $(SRC:%.c=%.o)

OBJ_DIR_BONUS = obj_bonus

OBJ_BONUS = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

bonus: $(OBJ_BONUS)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(OBJ_BONUS) $(OTHER_SOURCE) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft clean
	@make -C ./printf clean
	@rm -f $(OBJ)
	@rm -f $(OBJ_BONUS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./printf fclean
	rm -f $(NAME)

re: fclean all
	@make -C ./libft re
	@make -C ./printf re

.PHONY: all clean fclean re bonus
