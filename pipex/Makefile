NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c main.c

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

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

norminette:
	norminette $(SRC) pipex.h

norminette_all: norminette
	norminette $(SRC) ./libft/
	norminette $(SRC) ./printf/

gdb:
	gdb  --args  ./pipex

#--trace-children=yes per valgrind

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
