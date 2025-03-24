NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = main.c check.c atol.c print_men.c fill_philo.c forks.c death.c

ARG = 2 40 200 200 2

ARG2 = 5 810 200 200 7

ARG3= 200 800 200 200 5

ARG4 = 3 800 200 200 4

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
	./$(NAME) $(ARG) > file.txt

val: cleaning
	valgrind --tool=helgrind \
	--log-file=helgrind.log -s ./$(NAME) $(ARG3)

count: run
	grep "is eating" | wc -l

rm_val:
	rm -f helgrind.log

re: fclean all

.PHONY: all clean fclean re

.SILENT:



