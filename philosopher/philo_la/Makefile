NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = main.c check.c atol.c print_men.c fill_philo.c forks.c death.c \
		thread.c time.c lonely_boy.c

ARG = 4 410 200 100

ARG2 = 5 810 200 200 7

ARG3= 200 800 200 200 5

ARG4 = 2 24 100 100 2

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

cleaning:
	clear

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OTHER_SOURCE) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

get_sub:
	@wget -nc https://cdn.intra.42.fr/pdf/pdf/153341/en.subject.pdf

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

run: cleaning
	./$(NAME) $(ARG)

val: cleaning
	valgrind --tool=helgrind \
	--log-file=helgrind.log -s ./$(NAME) $(ARG)

count: run
	grep "is eating" | wc -l

rm_val:
	rm -f helgrind.log

re: fclean all

.PHONY: all clean fclean re




