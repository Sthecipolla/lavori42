#ifndef FDF_H
# define FDF_H

# include "minilibx-linux/mlx_int.h"
# include "./minilibx-linux/mlx.h"
# include "./printf/ft_printf.h"
# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
# include <X11/X.h>
# include <X11/keysym.h>


typedef struct l_map
{
	void		*session;
	void		*window;
	char		**map;
	int			coins;
	int			tot_coins;

}	t_map;

void	free_double_pointer(char **ptr);
int	ft_clean(t_map *s, int error);
int	len_col(char **map);
char	**create_a_copy_map(char **map);

#endif
