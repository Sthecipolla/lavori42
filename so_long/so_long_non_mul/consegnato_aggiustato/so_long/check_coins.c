/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_coins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:38:55 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 14:01:17 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_for_road(char **matrix, int i, int j)
{
	char	**copy_map;

	copy_map = create_a_copy_map(matrix);
	set_all_z(copy_map, i, j);
	if (check_for_zero(copy_map) == 0)
	{
		free_double_pointer(copy_map);
		return (0);
	}
	free_double_pointer(copy_map);
	return (1);
}

int	check_coins(char **matrix)
{
	int	i;
	int	j;

	i = -1;
	while (matrix[++i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
			if (matrix[i][j] == 'C')
			{
				if (check_for_road(matrix, i, j) == 0)
					return (0);
				return (1);
			}
			j++;
		}
	}
	return (0);
}
