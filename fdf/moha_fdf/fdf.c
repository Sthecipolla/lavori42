/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:34 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/03 11:14:21 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <X11/keysymdef.h>
#include <X11/keysym.h>

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;
	int		byte_per_pixel;
	int		vertical_offset;
	int		horizontal_offset;

	if (x < 0 || x >= WIN_X || y < 0 || y >= WIN_Y)
		return ;
	byte_per_pixel = data->bits_per_pixel / 8;
	vertical_offset = y * data->line_length;
	horizontal_offset = x * byte_per_pixel;
	dst = data->addr + (vertical_offset + horizontal_offset);
	*(unsigned int *)dst = color;
}

void	ft_set(t_point *p, int offset_x, int offset_y)
{
	p->x += offset_x;
	p->y += offset_y;
}

int	main(int ac, char **av)
{
	t_window	qwe;

	if (ac != 2)
	{
		perror("Usage: program-name map.fdf\n");
		return (1);
	}
	parsing(&qwe.mat, av[1]);
	qwe.mlx = mlx_init();
	qwe.win = mlx_new_window(qwe.mlx, WIN_X, WIN_Y, "FDF");
	qwe.img.img = mlx_new_image(qwe.mlx, WIN_X, WIN_Y);
	qwe.img.addr = mlx_get_data_addr(qwe.img.img, &qwe.img.bits_per_pixel,
			&qwe.img.line_length, &qwe.img.endian);
	qwe.zoom = 30;
	qwe.angle_x = 0.523599;
	qwe.angle_y = 0.523599;
	qwe.offset_x = 300;
	qwe.offset_y = 600;
	create_imagine(&qwe.mat, qwe.img, &qwe);
	mlx_put_image_to_window(qwe.mlx, qwe.win, qwe.img.img, 0, 0);
	mlx_hook(qwe.win, 17, 0, close_window, &qwe);
	mlx_key_hook(qwe.win, key_press, &qwe);
	mlx_loop_hook(qwe.mlx, handle_input, &qwe);
	mlx_loop(qwe.mlx);
	return (0);
}

/* void	create_imagine(t_mat *mat, t_image img, t_window *qwe)
{
	t_iter		iter;
	t_point_3	p;
	t_point_3	p1;
	int			s;

	iter.i = 0;
	while (mat->mat[iter.i])
	{
		iter.j = 0;
		while (iter.j < mat->x)
		{
			s = scale(qwe);
			ft_start_point2(&p1.p1, iter, s, mat->mat[iter.i][iter.j]);
			iso_projection(&p1.p1.x, &p1.p1.y, p1.p1.z, qwe);
			ft_set(&p1.p1, qwe->offset_x, qwe->offset_y);
			my_mlx_pixel_put(&img, p1.p1.x, p1.p1.y, 0x00FFFFFF);
			if (iter.j + 1 < mat->x)
			{
				ft_start_point3(&p1.p2, iter, s, mat->mat[iter.i][iter.j + 1]);
				iso_projection(&p1.p2.x, &p1.p2.y, p1.p2.z, qwe);
				ft_set(&p1.p2, qwe->offset_x, qwe->offset_y);
				ft_start_point(&p.p1, p1.p1.x, p1.p1.y, p1.p1.z);
				ft_start_point(&p.p2, p1.p2.x, p1.p2.y, p1.p2.z);
				draw_line(&img, p.p1, p.p2, 0x00FFFFFF);
			}
			if (mat->mat[iter.i + 1])
			{
				ft_start_point4(&p1.p3, iter, s, mat->mat[iter.i + 1][iter.j]);
				iso_projection(&p1.p3.x , &p1.p3.y, p1.p3.z, qwe);
				ft_set(&p1.p3, qwe->offset_x, qwe->offset_y);
				ft_start_point(&p.p1, p1.p1.x, p1.p1.y, p1.p1.z);
				ft_start_point(&p.p3, p1.p3.x , p1.p3.y, p1.p3.z);
				draw_line(&img, p.p1, p.p3, 0x00FFFFFF);
			}
			iter.j++;
		}
		iter.i++;
	}
} */
