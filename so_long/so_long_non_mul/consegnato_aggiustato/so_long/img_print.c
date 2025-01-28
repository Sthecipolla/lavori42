/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 17:28:21 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_position_second(t_map *prom, int x, int y)
{
	if (prom->map[x][y] == 'C')
	{
		mlx_put_image_to_window(prom->session, prom->window, \
		prom->imgarr[4].img, 32 * y, 32 * x);
	}
	else if (prom->map[x][y] == 'E')
	{
		mlx_put_image_to_window(prom->session, prom->window, \
		prom->imgarr[3].img, 32 * y, 32 * x);
	}
	else if (prom->map[x][y] == 'E')
	{
		mlx_put_image_to_window(prom->session, prom->window, \
		prom->imgarr[3].img, 32 * y, 32 * x);
	}
}

static int	get_position(t_map *prom)
{
	int	x;
	int	y;

	x = -1;
	while (prom->map[++x] != NULL)
	{
		y = 0;
		while (prom->map[x][y] != '\0')
		{
			if (prom->map[x][y] == '1')
			{
				mlx_put_image_to_window(prom->session, prom->window, \
				prom->imgarr[1].img, 32 * y, 32 * x);
			}
			else if (prom->map[x][y] == '0')
			{
				mlx_put_image_to_window(prom->session, prom->window, \
				prom->imgarr[2].img, 32 * y, 32 * x);
			}
			else
				get_position_second(prom, x, y);
			y++;
		}
	}
	return (0);
}

int	get_position_player(t_map *prom)
{
	int	x;
	int	y;

	x = 0;
	while (prom->map[x] != NULL)
	{
		y = 0;
		while (prom->map[x][y] != '\0')
		{
			if (prom->map[x][y] == 'P')
			{
				mlx_put_image_to_window(prom->session, prom->window, \
				prom->imgarr[0].img, 32 * y, 32 * x);
				return (0);
			}
			y++;
		}
		x++;
	}
	return (0);
}

int	fill_img(t_cr_image *str_img, void *session)
{
	str_img[0].img = mlx_xpm_file_to_image(session,
			"./textures/character.xpm", &str_img[0].width,
			&str_img[0].height);
	if (str_img[0].img == NULL)
		return (1);
	str_img[1].img = mlx_xpm_file_to_image(session, "./textures/wall.xpm",
			&str_img[1].width, &str_img[1].height);
	if (str_img[1].img == NULL)
		return (1);
	str_img[2].img = mlx_xpm_file_to_image(session, "./textures/road.xpm",
			&str_img[2].width, &str_img[2].height);
	if (str_img[2].img == NULL)
		return (1);
	str_img[3].img = mlx_xpm_file_to_image(session, "./textures/portal.xpm",
			&str_img[3].width, &str_img[3].height);
	if (str_img[3].img == NULL)
		return (1);
	str_img[4].img = mlx_xpm_file_to_image(session, "./textures/coin.xpm",
			&str_img[4].width, &str_img[4].height);
	if (str_img[4].img == NULL)
		return (1);
	return (0);
}

void	ft_img(t_map *prom)
{
	if (prom->imgarr[0].img == NULL)
	{
		if (fill_img(prom->imgarr, prom->session) == 1)
			ft_clean(prom, 12);
	}
	get_position(prom);
	get_position_player(prom);
}
