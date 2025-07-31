NAME = Bank

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

INCLUDES = -I ./

SOURCES= Account.cpp tests.cpp

all:$(NAME)

$(NAME):
	c++ $(INCLUDES) $(STD) $(SOURCES) -o $(NAME)

run: all
	clear
	./$(NAME)
	rm -f Bank

clear:

fclean: clear

re: fclean all
