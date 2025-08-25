NAME = animal

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

SRC = Animal.cpp Dog.cpp main.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp

all: $(NAME)

$(NAME): $(SRC)
	c++ $(CFLAG) $(STD) $(SRC) -o $(NAME)

run: re
	clear
	./$(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all run
