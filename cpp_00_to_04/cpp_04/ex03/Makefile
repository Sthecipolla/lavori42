NAME = littleGame

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

SRC = main.cpp ice.cpp cure.cpp aMateria.cpp character.cpp materiaSource.cpp

all: $(NAME)

$(NAME):
	c++ $(CFLAG) $(STD) $(SRC) -o $(NAME)

run: re
	clear
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all