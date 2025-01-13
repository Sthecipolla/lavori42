#ifndef SO_LONG_H
# define SO_LONG_H

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
} t_data;

# include "./minilibx-linux/mlx.h"
# include  "./printf/ft_printf.h"
# include  "./libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>

int	main(void);

#endif

