#include "so_long.h"

void	ft_img_men(t_map *prom)
{
	int		a;
	int		b;

	prom -> img = mlx_xpm_file_to_image(prom-> session,"./img_folder/Goku_s.xpm", &a, &b);
	if (prom -> img == NULL)
        ft_clean(prom,12);
	mlx_put_image_to_window(prom -> session , prom-> window, prom -> img, 1, 1);
}
