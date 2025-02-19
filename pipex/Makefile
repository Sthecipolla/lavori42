NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c main.c command.c

BONUS = pipex_bonus.c main_bonus.c command_bonus.c

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

OBJ_DIR_BONUS = obj_bonus

OBJ_BONUS = $(BONUS:%.c=$(OBJ_DIR_BONUS)/%.o)

all: $(NAME)
	clear

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

bonus: $(OBJ_BONUS)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(BONUS) $(OTHER_SOURCE) -o $(NAME)

$(OBJ_DIR_BONUS)/%.o: %.c
	@mkdir -p $(OBJ_DIR_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C ./libft clean
	@make -C ./printf clean
	rm -r -f $(OBJ_DIR)
	rm -r -f $(OBJ_DIR_BONUS)

fclean: clean
	@make -C ./libft fclean
	@make -C ./printf fclean
	rm -f $(NAME)
	clear

re: fclean all
	@make -C ./libft re
	@make -C ./printf re
	clear

#################################################################
norminette:
	norminette $(SRC) pipex.h

norminette_all: norminette
	norminette $(SRC) ./libft/
	norminette $(SRC) ./printf/

# gdb:
# 	gdb  --args  ./pipex

go:
	./pipex read.txt cat wc write.txt

# real_command:
# 	< read.txt cat | wc

# go_with_bonus:
# 	./pipex read.txt ls cat wc write.txt

# go_with_bonus_dox:
# 	./pipex "here_doc" ls cat wc write.txt

# vals:
# 	valgrind --trace-children=yes --track-fds=yes \
# 	./pipex read.txt ls cat write.txt

# prova_val:
# 	valgrind --trace-children=yes --track-fds=yes \
# 	--suppressions=supp.supp \
# 	./prova read.txt ls wc write.txt

# prova:elimina_prova
# 	cc prova.c command.c pipex.c $(OTHER_SOURCE) -o prova

# run_prova:
# 	./prova read.txt "ls" "wc" write.txt

# elimina_prova:
# 	rm -f prova


.PHONY: all clean fclean re
