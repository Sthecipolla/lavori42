#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx_int.h"
# include "./minilibx-linux/mlx.h"
# include  "./printf/ft_printf.h"
# include  "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct l_map
{
	void *session;
	void *window;
	char **map;
	void *img;

}t_map;

int check_border(char **map);
//int check_map(char **map);
int	main(void);
int check_portal(char	**matrix);
int check_player(char	**matrix);
int	check_coins(char	**matrix);
void free_double_pointer(char **ptr);
int	ft_clean(t_map *s, int error);
char **create_a_copy_map(char **map);
int check_for_zero(char	**matrix);
void	set_all_z(char	**map, int x, int y);
void print_map(char **map);
int	ft_input(int key_sim, t_map *s);
int	other_input(int key_sim, t_map *s);
void	create_map(t_map *mapstruct);
void	ft_img_men(t_map *img);


#endif

