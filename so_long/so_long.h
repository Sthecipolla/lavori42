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

}t_map;

int	main(void);

#endif

