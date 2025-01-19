#include "so_long.h"


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

int	check_other_char(char **matrix)
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

