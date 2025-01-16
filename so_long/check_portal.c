#include "so_long.h"

int check_portal(char	**matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
	j = 0;
		while (matrix[i][j] != '\0' || matrix[i][j] != '\n')
		{
		if(matrix[i][j] == 'P')
			return (1);
		j++;
		}
		i++;
	}
	return (0);
}
