NAME = megaphone

CFLAG = -Wall -Wextra -Werror

STD = -std=c++98

INCLUDES = -I ./

SOURCES= megaphone.cpp

all:
	c++ $(INCLUDES) $(CFLAG) $(STD) $(SOURCES) -o $(NAME)

run: all
	./megaphone
	rm -f megaphone

fclean:
	rm -f megaphone

.SILENT:
