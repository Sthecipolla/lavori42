#include "so_long.h"
static	int	check_other_char(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
	j = 0;
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
		if(matrix[i][j] != 'P' && matrix[i][j] != 'C')
		{
			if(matrix[i][j] != 'E' && matrix[i][j] != '1')
			{
				if(matrix[i][j] != '0')
					return (0);
			}
		}
		j++;
		}
		i++;
	}
	return (1);
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
static void	fill_map(t_map *map)
{
	char *str;
	int	x;
	int fd;
	int y;

	x = 0;
	y = -1;
	fd = open("text.bar",O_RDONLY ,777);
	if (fd < 0)
        exit(fd);
	str = ft_calloc(1,1);
	while(str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		x++;
	}
	close(fd);
	fd = open("text.bar",O_RDONLY ,777);
	if (fd < 0)
        exit(fd);
	map -> map =  (char **)malloc(x * sizeof(char*));
	while(++y < x - 1)
		map -> map[y] = get_next_line(fd);
	map -> map[y] = NULL;
}
void create_map(t_map *mapstruct)
{
	fill_map(mapstruct);
	if(check_map(mapstruct -> map) == 0)
		ft_clean(mapstruct, 11);
}
