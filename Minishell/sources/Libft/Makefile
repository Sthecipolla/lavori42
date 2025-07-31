# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 13:52:44 by daromoli          #+#    #+#              #
#    Updated: 2025/05/08 16:22:57 by daromoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	Name of the library
NAME = libft.a


#	Name of the sub-libraries
ORIGIN_LIBFT_NAME = libftoriginal.a
PRINTF_NAME = libftprintf.a
GNL_NAME = libftgnl.a


#	Source files
LIBFT_SOURCES =		$(addprefix Libft/,				\
					ft_isalpha.c					\
					ft_isdigit.c					\
					ft_isalnum.c					\
					ft_isascii.c					\
					ft_isprint.c					\
					ft_isspace.c					\
					ft_strlen.c						\
					ft_memset.c						\
					ft_bzero.c						\
					ft_memcpy.c						\
					ft_memmove.c					\
					ft_strlcpy.c					\
					ft_strlcat.c					\
					ft_toupper.c					\
					ft_tolower.c					\
					ft_strchr.c						\
					ft_strrchr.c					\
					ft_strncmp.c					\
					ft_memchr.c						\
					ft_memcmp.c						\
					ft_strnstr.c					\
					ft_atoi.c						\
					ft_calloc.c						\
					ft_strdup.c						\
					ft_substr.c						\
					ft_strjoin.c					\
					ft_strtrim.c					\
					ft_split.c						\
					ft_itoa.c						\
					ft_strmapi.c					\
					ft_striteri.c					\
					ft_putchar_fd.c					\
					ft_putstr_fd.c					\
					ft_putendl_fd.c					\
					ft_putnbr_fd.c					\
					ft_lstnew_bonus.c				\
					ft_lstadd_front_bonus.c			\
					ft_lstsize_bonus.c				\
					ft_lstlast_bonus.c				\
					ft_lstadd_back_bonus.c			\
					ft_lstdelone_bonus.c			\
					ft_lstclear_bonus.c				\
					ft_lstiter_bonus.c				\
					ft_lstmap_bonus.c)
PERSONAL_SOURCES =	$(addprefix Personal-Libft/,	\
					ft_max.c						\
					ft_min.c						\
					ft_strmap.c						\
					ft_atof.c						\
					ft_ltoa.c						\
					ft_lstrmnode.c)
PRINTF_SOURCES =	$(addprefix ft_printf/,			\
					ft_printf.c						\
					ft_put_char.c					\
					ft_put_string.c 				\
					ft_put_address.c				\
					ft_put_int_base.c				\
					ft_put_unsigned_int_base.c		\
					ft_put_unsigned_long_base.c)
GNL_SOURCES =		$(addprefix get_next_line/,		\
					get_next_line.c)


#	Object files
LIBFT_OBJ = ${LIBFT_SOURCES:.c=.o}
PERSONAL_OBJ = ${PERSONAL_SOURCES:.c=.o}
PRINTF_OBJ = ${PRINTF_SOURCES:.c=.o}
GNL_OBJ = ${GNL_SOURCES:.c=.o}


#	Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIB = ar rcs


#	ANSI escape codes for colorful messages
RED = \033[0;31m		# Red
GREEN = \033[0;32m		# Green
NC = \033[0m			# No Color


#	Structure of a rule in a Makefile
# 	target: prerequisetes
# 		command
# 		command
# 		command


#	First rule = default rule (running just make is equal to make all)
#	This rule is used to make the complete library (no math)
.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT_OBJ) $(PERSONAL_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@ $(LIB) $(NAME) $(LIBFT_OBJ) $(PERSONAL_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@ echo "$(GREEN)$(NAME) created!$(NC)"


#	This rule is used to make the original libft (no printf or get_next_line)
.PHONY: original-libft
original-libft: $(ORIGIN_LIBFT_NAME)

$(ORIGIN_LIBFT_NAME): $(LIBFT_OBJ) $(PERSONAL_OBJ)
	@ $(LIB) $(ORIGIN_LIBFT_NAME) $(LIBFT_OBJ) $(PERSONAL_OBJ)
	@ echo "$(GREEN)$(ORIGIN_LIBFT_NAME) created!$(NC)"


#	This rule is used to make libft + printf (no get_next_line)
.PHONY: printf
printf: $(PRINTF_NAME)

$(PRINTF_NAME): $(LIBFT_OBJ) $(PERSONAL_OBJ) $(PRINTF_OBJ)
	@ $(LIB) $(PRINTF_NAME) $(LIBFT_OBJ) $(PERSONAL_OBJ) $(PRINTF_OBJ)
	@ echo "$(GREEN)$(PRINTF_NAME) created!$(NC)"


#	This rule is used to make libft + get_next_line (no printf)
.PHONY: gnl
gnl: $(GNL_NAME)

$(GNL_NAME): $(LIBFT_OBJ) $(PERSONAL_OBJ) $(GNL_OBJ)
	@ $(LIB) $(GNL_NAME) $(LIBFT_OBJ) $(PERSONAL_OBJ) $(GNL_OBJ)
	@ echo "$(GREEN)$(GNL_NAME) created!$(NC)"

	
#	Pattern rule that compiles every .c file into a .o file
#	Meaning of the symbols:
#		$@ = target name
#		$? = all prerequisites newer than the target
#		$^ = all prerequisites
#		$< = the first prerequisite
%.o: %.c
	@ $(CC) -c $< -o $@ $(CFLAGS)
	

#	The rule clean removes all the temporary generated files
.PHONY: clean
clean:
	@ rm -f $(LIBFT_OBJ) $(PERSONAL_OBJ) $(PRINTF_OBJ) $(GNL_OBJ)
	@ echo "$(RED)Libft objects files removed$(NC)"


#	The rule fclean is a make clean plus all the binary made with make all
.PHONY: fclean
fclean: clean
	@ rm -f $(NAME) $(ORIGIN_LIBFT_NAME) $(PRINTF_NAME) $(GNL_NAME)
	@ echo "$(RED)Libft libraries removed$(NC)"


#	The rule re is a make fclean followed by make all
.PHONY: re
re: fclean all
