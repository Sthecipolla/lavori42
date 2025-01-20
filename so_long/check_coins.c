#include "so_long.h"

int check_coins(char	**matrix)
{
	int	i;
	int	j;
	char	**copy_map;

	i = -1;
	while (matrix[++i] != NULL)
	{
	j = 0;
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
		if(matrix[i][j] == 'C')
		{
			copy_map = create_a_copy_map(matrix);
			set_all_z(copy_map, i, j);
			if(check_for_zero(copy_map) == 0)
			{
				free_double_pointer(copy_map);
				return (0);
			}
			return (1);
		}
		j++;
		}
	}
	return (0);
}
