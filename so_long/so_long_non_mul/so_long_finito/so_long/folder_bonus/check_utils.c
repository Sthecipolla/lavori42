/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:02 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 14:46:59 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_all_z(char **map, int x, int y)
{
	if (map[x][y] == 'E')
		map[x][y] = '1';
	if (map[x][y] == 'T')
		map[x][y] = '1';
	if (map[x][y] == '1' || map[x][y] == 'z')
		return ;
	map[x][y] = 'z';
	set_all_z(map, x + 1, y);
	set_all_z(map, x - 1, y);
	set_all_z(map, x, y + 1);
	set_all_z(map, x, y - 1);
}

int	check_for_zero(char **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == 'C' || matrix[i][j] == 'P'
				|| matrix[i][j] == 'E')
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
			if (matrix[i][j] != 'P' && matrix[i][j] != 'C')
			{
				if (matrix[i][j] != 'E' && matrix[i][j] != '1')
				{
					if (matrix[i][j] != '0' && matrix[i][j] != 'T')
						return (0);
				}
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_pos_player(char **matrix, int x)
{
	int	i;
	int	j;

	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0')
		{
			if (matrix[i][j] == 'P')
			{
				if (x == 0)
					return (i);
				return (j);
			}
			j++;
		}
		i++;
	}
	return (1);
}
