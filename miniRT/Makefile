# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 09:59:56 by daromoli          #+#    #+#              #
#    Updated: 2025/07/22 12:34:22 by daromoli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#	Name of the program
NAME = miniRT


#	Source files
SOURCES =	sources/main.c							\
			$(addprefix sources/cleanup/,			\
			cleanup.c								\
			expand_clean.c)							\
			$(addprefix sources/errors/,			\
			error_management.c)						\
			$(addprefix sources/mlx_events/,		\
			change_obj_properties.c					\
			change_light_properties.c				\
			events_keyboard.c						\
			events_mouse.c							\
			select_objs_lights.c					\
			update_render.c							\
			camera_rotation.c						\
			camera_translation.c					\
			object_rotation.c						\
			object_translation.c)					\
			$(addprefix sources/colors/,			\
			colors_management.c						\
			colors_palettes.c						\
			colors_utils1.c							\
			colors_utils2.c)						\
			$(addprefix sources/init/,				\
			copy_scene.c							\
			copy_scene_obj.c						\
			init_data.c								\
			init_render.c)							\
			$(addprefix sources/render/,			\
			render.c								\
			rays.c									\
			hit_anything.c							\
			hit_sphere.c							\
			hit_plane.c								\
			hit_cylinder.c							\
			hit_cylinder_wall.c						\
			hit_cylinder_basis.c					\
			lighting.c								\
			object_utils.c							\
			light_utils.c)							\
			$(addprefix sources/parsing/,			\
			ambient_light.c							\
			add_obj.c								\
			camera.c								\
			control_conversion.c					\
			cylinder.c								\
			error_mess.c							\
			light.c									\
			parsing.c								\
			plane.c									\
			read_file_sec.c							\
			reading_file.c							\
			sphere.c								\
			utils.c)
HEADERS =	$(addprefix includes/,					\
			miniRT_enums.h							\
			miniRT_errors.h							\
			miniRT_external.h						\
			miniRT_functions.h						\
			miniRT_images.h							\
			miniRT_math.h							\
			miniRT_parsing.h						\
			miniRT_render.h							\
			miniRT_structs.h						\
			miniRT.h)
			


#	Object files
OBJECTS := ${SOURCES:.c=.o}


#	Libft path and file
LIBFT = Libft/mathlibft.a
LIBFT_PATH = Libft/
LIBFT_MAKE_RULE = math


#	Minilibx path and file
MLX = Minilibx/libmlx.a
MLX_PATH = Minilibx/


#	Compiler and flags
#	Basics flags
#	-g:				It includes debugging information in the compiled program.
#					It is needed to debug with gdb.
#	-Wall:			It enables commonly used warning messages such as unused
#					variables and uninitialized variables.
#	-Wextra:		It enables additional warning messages not included in
#					-Wall.
#	-Werror:		Treats all warnings as errors.
#	Minilibx and fractol flags
#	-I/usr/include:	Instructs the compiler to include the include directory
#					when searching for necessary header files.
#	-IMinilibx:		Adds the Minilibx directory as an additional path for
#					header files, so <mlx.h> can be included.
#	-O3:			Enables the highest level of code optimization during
#					compilation. This can improve the program's performance
#					but may increase compilation time.
#	-LMinilibx:		Specifies the Minilibx directory as a path for libraries
#					during the linking phase.
#	-lmlx:			Instructs the linker to use the libmlx.a or libmlx.so
#					library (depending on the type of library available).
#	-L/usr/lib: 	Adds lib as a path for system libraries.
#	-lXext -lX11:	Link the libXext and libX11 libraries, which are required 
#					for interacting with the X Window System on Linux.
#	-lz:			Links the zlib compression library, useful for handling
#					compressed files or data streams.
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
MLX_OBJ_FLAGS = -I/usr/include -IMinilibx -O3
OBJ_FLAGS = -Iincludes -I$(LIBFT_PATH)
MLX_FLAGS = -LMinilibx -lmlx -L/usr/lib -IMinilibx -lXext -lX11 -lz
MATH_FLAGS = -lm


#	Valgrind flags
VALGRIND = /usr/bin/valgrind
VAL_FLAGS =	-s								\
			--leak-check=full				\
			--track-origins=yes				\
			--show-reachable=yes			\
			--show-leak-kinds=all			\
			--track-fds=yes					\
			--trace-children=yes
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


#	Rule that compiles the program pipex
.PHONY: all
all: $(NAME)

$(NAME): $(MLX) $(OBJECTS) $(LIBFT)
	@ $(CC) $^ -o $@ $(CFLAGS) $(MLX_FLAGS) $(MATH_FLAGS)
	@ echo "$(GREEN)$(NAME) compiled!$(NC)"

#	Pattern rule that compiles every .c file into a .o file
#	Meaning of the symbols:
#		$@ = target name
#		$? = all prerequisites newer than the target
#		$^ = all prerequisites
#		$< = the first prerequisite
%.o: %.c
	@ $(CC) -c $< -o $@ $(CFLAGS) $(OBJ_FLAGS) $(MLX_OBJ_FLAGS)


#	Rule that compiles the libft by using its Makefile
$(LIBFT):
	@ echo "$(NC)Compiling Libft...$(NC)"
	@ $(MAKE) $(LIBFT_MAKE_RULE) -C $(LIBFT_PATH)


#	Rule that compiles the minilibx by using its Makefile
$(MLX):
	@ echo "$(NC)Compiling Minilibx...$(NC)"
	@ $(MAKE) -s -C $(MLX_PATH)


#	The rule norminette executes norminette on all the source and header files
.PHONY:	norminette
norminette:
	norminette $(SOURCES) $(HEADERS)
	@ $(MAKE) norminette -C $(LIBFT_PATH)


#	The rule mlx download the Minilibx and put it in the correct directory
.PHONY: mlx
mlx: $(MLX_PATH)

$(MLX_PATH):
	@ rm -rf $(MLX_PATH)
	@ wget https://cdn.intra.42.fr/document/document/34955/minilibx-linux.tgz
	@ tar -xz -f minilibx-linux.tgz
	@ mv minilibx-linux $(MLX_PATH)
	@ rm -rf $(MLX_PATH).git $(MLX_PATH).github
	@ rm -rf minilibx-linux.tgz


#	Rules that compile the program miniRT and executes it with valgrind
PROGRAM_ARGS = scenes/complex/all-white-complex-multiple-lights.rt

.PHONY: valgrind
valgrind: $(NAME)
	$(VALGRIND) $(VAL_FLAGS) ./$(NAME) $(PROGRAM_ARGS)

.PHONY: val
val: $(NAME)
	$(VALGRIND) $(VAL_FLAGS) $(VAL_QFLAG) ./$(NAME) $(PROGRAM_ARGS)

.PHONY: run
run: $(NAME)
	./$(NAME) $(PROGRAM_ARGS)

#	The rule clean removes all the temporary generated files
.PHONY: clean
clean:
	@ rm -f $(OBJECTS)
	@ $(MAKE) clean -C $(LIBFT_PATH)
	@ $(MAKE) clean -s -C $(MLX_PATH)
	@ echo "$(RED)Objects files removed$(NC)"


#	The rule fclean is a make clean plus all the binary made with make all
.PHONY: fclean
fclean: clean
	@ rm -f $(NAME)
	@ $(MAKE) fclean -C $(LIBFT_PATH)
	@ echo "$(RED)Libraries removed$(NC)"


#	The rule re is a make fclean followed by make all
.PHONY: re
re: fclean all
