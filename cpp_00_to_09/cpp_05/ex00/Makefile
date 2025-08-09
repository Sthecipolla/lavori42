NAME = Bureaucrat

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

SRC = main.cpp Bureaucrat.cpp

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

.PHONY: re fclean clean all run