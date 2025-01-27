/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_border.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:38:52 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 11:43:56 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_wall_all_alline(char **map)
{
	int	col;
	int	index;
	int	app;

	col = ft_strlen(map[0]);
	index = 0;
	while (map[index] != NULL)
	{
		app = (int)ft_strlen(map[index]);
		if (app != col)
			return (0);
		index++;
	}
	return (1);
}

static int	check_border_are_all_close(char **map)
{
	int	col;
	int	linee;
	int	mx_len_col;
	int	mx_len_linee;

	mx_len_linee = len_col(map) - 1;
	mx_len_col = ft_strlen(map[0]) - 1;
	col = -1;
	while (++col <= mx_len_col)
	{
		if (map[0][col] != '1' || map[mx_len_linee][col] != '1')
			return (0);
	}
	linee = -1;
	while (++linee <= mx_len_linee)
	{
		if (map[linee][0] != '1' || map[linee][mx_len_col] != '1')
			return (0);
	}
	return (1);
}

int	check_border(char **map)
{
	if (check_wall_all_alline(map) == 0)
		return (0);
	if (check_border_are_all_close(map) == 0)
		return (0);
	return (1);
}
