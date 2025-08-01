/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:38:57 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 11:38:57 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_player(char **matrix)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != '\0' && matrix[i][j] != '\n')
		{
			if (matrix[i][j] == 'P')
			{
				count++;
				if (count == 2)
					return (0);
			}
			j++;
		}
		i++;
	}
	if (count == 1)
		return (1);
	return (0);
}
