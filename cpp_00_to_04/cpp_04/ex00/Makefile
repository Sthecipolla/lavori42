NAME = animal

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

SRC = animal.cpp dog.cpp main.cpp cat.cpp

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