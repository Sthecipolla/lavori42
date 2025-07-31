# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/28 12:19:18 by daromoli          #+#    #+#              #
#    Updated: 2025/05/20 13:46:28 by daromoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Name of the program
NAME = minishell


#	Source files
SOURCES =	$(addprefix sources/,			\
			main.c							\
			$(addprefix cleanup/,			\
			free_char_matrixes.c			\
			ft_cleanup.c)					\
			errors/error_management.c		\
			$(addprefix execute/,			\
			line_to_table.c					\
			line_to_table_utils.c			\
			reorder_cmd_line.c				\
			reorder_cmd_line_utils.c		\
			redirections.c					\
			manage_env_vars.c				\
			args_path_finder.c				\
			execute.c						\
			execute_child.c					\
			here_doc.c)						\
			$(addprefix signals/,			\
			signals.c						\
			signal_handlers.c)				\
			$(addprefix parsing/,			\
			base_work.c						\
			parsing.c						\
			free_before_exit.c				\
			syntax_error.c					\
			struct_split_utils.c			\
			struct_split.c					\
			utils.c							\
			var_expand_utils.c				\
			var_expand.c					\
			here_doc.c						\
			here_doc_expand.c				\
			parsi_utils.c					\
			find_string.c					\
			parsing_utils_sec.c)			\
			$(addprefix builtin/,			\
			builtin_utils.c					\
			builtin_echo.c					\
			builtin_exit.c					\
			builtin_env.c					\
			builtin_pwd.c					\
			builtin_export.c				\
			builtin_export_print_utils.c	\
			builtin_export_add_utils.c		\
			builtin_unset.c					\
			builtin_cd.c))


#	Object files
OBJECTS = ${SOURCES:.c=.o}


#	Libft path and file
LIBFT = sources/Libft/libft.a
LIBFT_PATH = sources/Libft/


#	Compiler and flags
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
OBJFLAGS = -I./includes -I./$(LIBFT_PATH)
LINKFLAGS = -lreadline


#	Valgrind suppressions files
EXE_SUPP = $(CURDIR)/executables.supp
RDL_SUPP = $(CURDIR)/readline.supp


#	Valgrind flags
VALGRIND = /usr/bin/valgrind
VAL_FLAGS =	-s								\
			--leak-check=full				\
			--track-origins=yes				\
			--show-reachable=yes			\
			--show-leak-kinds=all			\
			--track-fds=yes					\
			--trace-children=yes			\
			--suppressions=$(EXE_SUPP)		\
			--suppressions=$(RDL_SUPP)
#			--gen-suppressions=all
VAL_QFLAG = -q


#	ANSI escape codes for colorful messages
RED = \033[0;31m		# Red
GREEN = \033[0;32m		# Green
NC = \033[0m			# No Color


#	Structure of a rule in a Makefile
# 	target: prerequisetes
# 		command
# 		command
# 		command


#	Rule that compiles the program minishell
.PHONY: all
all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@ echo "$(NC)Linking...$(NC)"
	@ $(CC) $(OBJECTS) $(LIBFT) -o $(NAME) $(CFLAGS) $(LINKFLAGS)
	@ echo "$(GREEN)$(NAME) compiled!$(NC)"


#	Pattern rule that compiles every .c file into a .o file
#	Meaning of the symbols:
#		$@ = target name
#		$? = all prerequisites newer than the target
#		$^ = all prerequisites
#		$< = the first prerequisite
%.o: %.c
	@ $(CC) -c $< -o $@ $(CFLAGS) $(OBJFLAGS)


#	Rule that compiles the libft by using its Makefile
$(LIBFT):
	@ echo "$(NC)Compiling Libft...$(NC)"
	@ $(MAKE) -C $(LIBFT_PATH)


#	Rules that compile the program minishell and executes it with valgrind
.PHONY: valgrind
valgrind: $(NAME)
	$(VALGRIND) $(VAL_FLAGS) ./$(NAME)

.PHONY: val
val: $(NAME)
	$(VALGRIND) $(VAL_FLAGS) $(VAL_QFLAG) ./$(NAME)


#	Rule that compiles the program minishell and executes it
.PHONY: run
run: $(NAME)
	./$(NAME)


#	The rule clean removes all the temporary generated files
.PHONY: clean
clean:
	@ rm -f $(OBJECTS) $(BONUS_OBJ)
	@ $(MAKE) clean -C $(LIBFT_PATH)
	@ echo "$(RED)Objects files removed$(NC)"


#	The rule fclean is a make clean plus all the binary made with make all
.PHONY: fclean
fclean: clean
	@ rm -f $(NAME) $(BONUS_NAME)
	@ $(MAKE) fclean -C $(LIBFT_PATH)
	@ echo "$(RED)Libraries removed$(NC)"


#	The rule re is a make fclean followed by make all
.PHONY: re
re: fclean all
