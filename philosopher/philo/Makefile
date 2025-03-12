NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = main.c check.c atol.c

ARG = 4 410 200 200 200

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

get_sub:
	@wget -nc https://cdn.intra.42.fr/pdf/pdf/153341/en.subject.pdf
	clear

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

val:
	valgrind -fsanitize=thread ./$(NAME) $(ARG)

re: fclean all

.PHONY: all clean fclean re

.SILENT:
