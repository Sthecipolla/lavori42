NAME = PhoneBook

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

INCLUDES = -I ./

SOURCES= PhoneBook.cpp Main.cpp Contact.cpp

all:
	c++ $(INCLUDES) $(CFLAG) $(STD) $(SOURCES) -o $(NAME)

run: all
	clear
	./$(NAME)
	rm -f PhoneBook


fclean:
	rm -f PhoneBook

.SILENT:
