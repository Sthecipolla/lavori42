NAME = checker

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

OTHER_SOURCE = -L../libft -l:libft.a -L../printf -l:libftprintf.a

N = 3 12 14 90 21 554

SRC = main.c rotate.c swap.c push.c reverse.c

APP = app

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)
	clear

$(NAME): $(OBJ)
	@make -C ../libft
	@make -C ../printf
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make -C ../libft clean
	@make -C ../printf clean
	rm -f $(OBJ)
	rm -r obj
	clear

fclean: clean
	@make -C ../libft fclean
	@make -C ../printf fclean
	rm -f $(NAME)
	clear

re: fclean all
	@make -C ../libft re
	@make -C ../printf re
	clear

.PHONY: all clean fclean re
