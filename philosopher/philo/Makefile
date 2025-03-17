NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = main.c check.c atol.c print_men.c fill_philo.c

ARG = 4 410 200 200 3

ARG2 = 5 810 200 200 7

OBJ = $(SRC:%.c=%.o)

all: cleaning $(NAME) clean

cleaning:
	clear

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

run: cleaning
	./$(NAME) $(ARG2)

val:
	valgrind ./$(NAME) $(ARG)

re: fclean all

.PHONY: all clean fclean re

.SILENT:



