/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:16 by lhima             #+#    #+#             */
/*   Updated: 2025/02/13 10:48:09 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	linee_count(t_map *c, int x, char *file)
{
	char	*str;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_clean(c, 13);
	str = ft_calloc(1, 1);
	if (str == NULL)
		return (0);
	while (str != NULL)
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
	int	fd;
	int	y;

	y = -1;
	x = linee_count(map, 0, file);
	if (x == 0)
		ft_clean(map, 13);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_clean(map, 11);
	map->map = (char **)malloc(x * sizeof(char *));
	if (!map)
		ft_clean(map, 11);
	while (++y < x - 1)
	{
		map->map[y] = get_next_line(fd);
		if (map->map[y] == NULL)
			ft_clean(map, 11);
	}
	map->map[y] = NULL;
	close(fd);
}

void	create_map(t_map *app, char *file)
{
	fill_map(app, file);
	/* if (check_map(app) == 0)
		ft_clean(app, 11); */
}
