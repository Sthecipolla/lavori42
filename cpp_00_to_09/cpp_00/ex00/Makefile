NAME = megaphone

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

INCLUDES = -I ./

SOURCES= megaphone.cpp

all:$(NAME)

$(NAME):
	c++ $(INCLUDES) $(CFLAG) $(STD) $(SOURCES) -o $(NAME)
	

run: all
	./megaphone
	rm -f megaphone

clear:

fclean: clear
	rm -f megaphone

re: fclean all

# .SILENT:
