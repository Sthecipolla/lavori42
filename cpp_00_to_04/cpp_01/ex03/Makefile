NAME = Zombie

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

COM = c++

SRC = main.cpp HumanB.cpp HumanA.cpp Weapon.cpp

all: $(NAME)

$(NAME):
	$(COM) $(CFLAG) $(STD) $(SRC) -o $(NAME)

clean:

fclean: clean
	rm -f $(NAME)

re: fclean all