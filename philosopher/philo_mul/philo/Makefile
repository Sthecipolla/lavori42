NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -pthread -g

SRC = main.c check.c atol.c print_men.c fill_philo.c forks.c death.c \
		thread.c time.c lonely_boy.c

ARG = 5 1200 200 200 7

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

get_sub:
	@wget -nc https://cdn.intra.42.fr/pdf/pdf/153341/en.subject.pdf
	
run:
	./$(NAME) $(ARG)

val:
	valgrind --tool=helgrind --tool=memcheck \
	--log-file=helgrind.log -s ./$(NAME) $(ARG)

clean:
	@rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re run val get_sub




