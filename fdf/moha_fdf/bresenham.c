/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:09 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:46:12 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_dx_dy(t_point p1, t_point p2, int *dx, int *dy)
{
	*dx = abs(p2.x - p1.x);
	*dy = abs(p2.y - p1.y);
}

void	calculate_step(t_point p1, t_point p2, int *sx, int *sy)
{
	if (p1.x < p2.x)
		*sx = 1;
	else
		*sx = -1;
	if (p1.y < p2.y)
		*sy = 1;
	else
		*sy = -1;
}

void	calculate_error(int dx, int dy, int *err)
{
	*err = dx - dy;
}

void	draw_point(t_image *img, t_point p, int color)
{
	my_mlx_pixel_put(img, p.x, p.y, color);
}

void	draw_line(t_image *img, t_point p1, t_point p2, int color)
{
	t_line	line;

	calculate_dx_dy(p1, p2, &line.dx, &line.dy);
	calculate_step(p1, p2, &line.sx, &line.sy);
	calculate_error(line.dx, line.dy, &line.err);
	while (1)
	{
		draw_point(img, p1, color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		line.e2 = line.err * 2;
		if (line.e2 > -(line.dy))
		{
			line.err -= line.dy;
			p1.x += line.sx;
		}
		if (line.e2 < line.dx)
		{
			line.err += line.dx;
			p1.y += line.sy;
		}
	}
}
