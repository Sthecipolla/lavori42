#include "so_long.h"

int fill_img(t_cr_image *str_img, void *session)
{
	str_img[0].img = mlx_xpm_file_to_image(session,"./img_folder/Goku_e_basta.xpm", &str_img[0].width,  &str_img[0].height);
	if(str_img[0].img == NULL)
		return (1);
	str_img[1].img = mlx_xpm_file_to_image(session,"./img_folder/wall.xpm",&str_img[1].width,  &str_img[1].height);
	if(str_img[1].img == NULL)
		return (1);
	str_img[2].img = mlx_xpm_file_to_image(session,"./img_folder/road.xpm",&str_img[2].width,  &str_img[2].height);
	if(str_img[2].img == NULL)
		return (1);
	str_img[3].img = mlx_xpm_file_to_image(session,"./img_folder/portal.xpm",&str_img[3].width,  &str_img[3].height);
	if(str_img[3].img == NULL)
		return (1);
	str_img[4].img = NULL;
	return (0);
}
static int	check_map(char **map)
{

	//coin;
	if(check_border(map) == 0)
		return (0);
	if(check_coins(map) == 0)
		return(0);
	if(check_portal(map) == 0)
		return (0);
	if(check_player(map) == 0)
		return(0);
	if(check_other_char(map) == 0)
		return (0);
	return (1);
}
static int	linee_count(int x)
{
	char *str;
	int fd;
	fd = open("text.bar",O_RDONLY);
	if (fd < 0)
        exit(fd);
	str = ft_calloc(1,1);
	if (str == NULL)
		return (0);
	
	while(str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		x++;
	}
	close(fd);
	return (x);
}
static void	fill_map(t_map *map)
{
	int	x;
	int fd;
	int y;

	y = -1;
	x = linee_count(0);
	if(x == 0)
		ft_clean(map, 11);
	fd = open("text.bar",O_RDONLY);
	if (fd < 0)
        ft_clean(map, 11);
	map -> map =  (char **)malloc(x * sizeof(char*));
	if (!map)
		ft_clean(map, 11);
	while(++y < x - 1)
	{
		map -> map[y] = get_next_line(fd);
		if (map -> map[y] == NULL)
			ft_clean(map, 11);
	}
	map -> map[y] = NULL;
	close(fd);
}
void create_map(t_map *app)
{
	fill_map(app);
	if(check_map(app -> map) == 0)
		ft_clean(app, 11);
	if(fill_img(app -> imgarr,app -> session) == 1)
		ft_clean(app, 12);
}
