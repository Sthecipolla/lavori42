NAME = pipex

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

#exe sintassi se vuoi modificarla dall'esterno EXE="main.c cat 'wc -l' out"
EXE = main.c cat wc out

SRC = pipex.c main.c command.c

BONUS = pipex_bonus.c main_bonus.c command_bonus.c

NAME_BONUS = pipex_bonus

SUPPRESSION_FILE =	"{\n\
					MALLOC FAILURE OF /usr/bin/*\n\
					Memcheck:Leak\n\
					fun:malloc\n\
					...\n\
					obj:/usr/bin/*\n\
					}\n\
					{\n\
					CALLOC FAILURE of /usr/bin/*\n\
					Memcheck:Leak\n\
					fun:calloc\n\
					...\n\
					obj:/usr/bin/*\n\
					}\n\
					{\n\
					REALLOC FAILURE of /usr/bin/*\n\
					Memcheck:Leak\n\
					fun:realloc\n\
					...\n\
					obj:/usr/bin/*\n\
					}"

OTHER_SOURCE = -L./libft -l:libft.a -L./printf -l:libftprintf.a

OBJ = $(SRC:%.c=%.o)

OBJ_BONUS = $(BONUS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C ./libft
	@make -C ./printf
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
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

rebonus: fclean bonus
	@make -C ./libft re
	@make -C ./printf re

supp: rem_supp
	touch supp.supp
	echo $(SUPPRESSION_FILE) >> supp.supp

rem_supp:
	rm -f supp.supp

valgrind:
	valgrind --trace-children=yes \
	--track-fds=yes --suppressions=supp.supp \
	./pipex $(EXE)

.PHONY: all clean fclean re bonus supp rem_supp rebonus valgrind
