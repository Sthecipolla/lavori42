NAME = Zombie

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

SRC = main.cpp

all: $(NAME)

$(NAME):
	c++ $(CFLAG) $(STD) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all