NAME = Harl

CFLAG = -Wall -Wextra -Werror -g

STD = -std=c++98

COM = c++

SRC = main.cpp Harl.cpp

all: $(NAME)

$(NAME):
	$(COM) $(CFLAG) $(STD) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all