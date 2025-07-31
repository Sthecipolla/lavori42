NAME = rep_file

CFLAG = -Wall -Wextra -Werror -g

STD = -std=c++98

COM = c++

SRC = main.cpp

all: $(NAME)

$(NAME):
	$(COM) $(CFLAG) $(STD) $(SRC) -o $(NAME)

run: all
	./file main.cpp name ciao

val:
	valgrind ./file main.cpp name ciao

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all