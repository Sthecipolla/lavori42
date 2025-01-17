#include "so_long.h"

char **create_a_copy_map(char **map)
{
    int rows;
	char **new_map;

	rows = 0;
    while (map[rows] != NULL)
        rows++;
    new_map = (char **)malloc((rows + 1) * sizeof(char *));
	if(!new_map)
	{
		free(new_map);
		return (NULL);
	}
	new_map[rows] = NULL;
	rows = 0;
	while(map[rows] != NULL)
	{
		new_map[rows] = ft_strdup(map[rows]);
		if(!new_map[rows])
		{
			free_double_pointer(new_map);
			return (NULL);
		}
		rows++;
	}
	return (new_map);
}
void	set_all_z(char	**map, int x, int y)
{
	if(map[x][y] == '1' || map[x][y] == 'z')
		return;
	map[x][y] = 'z';
	set_all_z(map, x + 1, y);
	set_all_z(map, x - 1, y);
	set_all_z(map, x, y + 1);
	set_all_z(map, x, y - 1);
}
int check_for_zero(char	**matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
	j = 0;
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
		if(matrix[i][j] == 'C' || matrix[i][j] == 'P' || matrix[i][j] == 'E')
				return (0);
		j++;
		}
		i++;
	}
	return (1);
}

