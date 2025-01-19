#include "so_long.h"
static int	get_position(t_map *prom)
{
	int		x;
	int		y;

	x = 0;
	while (prom -> map[x] != NULL)
	{
		y = 0;
		while (prom -> map[x][y] != '\0')
		{
			if (prom -> map[x][y] == '1')
				mlx_put_image_to_window(prom -> session , prom-> window, prom -> imgarr[1].img, x, y);
			else if(prom -> map[x][y] == '0')
				mlx_put_image_to_window(prom -> session , prom-> window, prom -> imgarr[2].img, x, y);
			/* if (prom -> map[x][y] == 'C')
				mlx_put_image_to_window(prom -> session , prom-> window, prom -> img, x, y); */
			else if(prom -> map[x][y] == 'E')
				mlx_put_image_to_window(prom -> session , prom-> window, prom -> imgarr[3].img, x, y);
			y++;
		}
		x++;
	}
	return (0);
}

int get_position_player(t_map *prom)
{
	int		x;
	int		y;
	int 	i;
 	int 	i2;

	
	x = 0;
	while (prom -> map[x] != NULL)
	{
		y = 0;
		while (prom -> map[x][y] != '\0')
		{
			if (prom -> map[x][y] == 'P')
			{
				i = lenCol(prom -> map) * x;
				i2 = ft_strlen(prom -> map[0]) * y;
				mlx_put_image_to_window(prom -> session , prom-> window, prom -> imgarr[0].img, 1920/i, 1080/i2);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	ft_img(t_map *prom)
{

	fill_img(prom -> imgarr, prom -> session);
	get_position(prom);
	get_position_player(prom);
	//return (0);
}
