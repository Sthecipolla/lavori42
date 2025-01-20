#include "so_long.h"

static int calc_coins(char ** matrix)
{
	int	i;
	int	j;
	int coins;

	coins = 0;
	i = 0;
	while (matrix[i] != NULL)
	{
	j = 0;
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
		if(matrix[i][j] == 'C')
			coins++;
		j++;
		}
		i++;
	}
	return (coins);
}
static int	check_map(t_map *app)
{

	if(check_border(app -> map) == 0)
		return (0);
	if( check_coins(app -> map) == 0)
		return(0);
	else
		app ->tot_coins = calc_coins(app -> map);
	if(check_portal(app -> map) == 0)
		return (0);
	if(check_player(app -> map) == 0)
		return(0);
	if(check_other_char(app -> map) == 0)
		return (0);
	return (1);
}
static int	linee_count(t_map *c, int x,char *file)
{
	char *str;
	int fd;
	fd = open(file,O_RDONLY);
	if (fd < 0)
        ft_clean(c, 13);
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
static void	fill_map(t_map *map, char *file)
{
	int	x;
	int fd;
	int y;

	y = -1;
	x = linee_count(map,0,file);
	if(x == 0)
		ft_clean(map, 13);
	fd = open(file,O_RDONLY);
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
void create_map(t_map *app,char *file)
{
	app ->coins=0;
	fill_map(app,file);
	if(check_map(app) == 0)
		ft_clean(app, 11);
}
