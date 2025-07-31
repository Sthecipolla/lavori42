/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:27 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:46:30 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Funzione per disegnare il punto corrente nella matrice
void	draw_current_point(t_drawing_context *ctx, t_point_3 *p1, t_iter iter)
{
	ft_start_point2(&p1->p1, iter, ctx->scale, ctx->mat->mat[iter.i][iter.j]);
	iso_projection(&p1->p1.x, &p1->p1.y, p1->p1.z, ctx->qwe);
	ft_set(&p1->p1, ctx->qwe->offset_x, ctx->qwe->offset_y);
	my_mlx_pixel_put(ctx->img, p1->p1.x, p1->p1.y, 0x00FFFFFF);
}
// Funzione per disegnare la linea orizzontale

void	draw_horizontal_l(t_drawing_context *ctx, t_point_3 *p1, t_iter iter)
{
	if (iter.j + 1 < ctx->mat->x)
	{
		ft_start_point3(&p1->p2, iter, ctx->scale,
			ctx->mat->mat[iter.i][iter.j + 1]);
		iso_projection(&p1->p2.x, &p1->p2.y, p1->p2.z, ctx->qwe);
		ft_set(&p1->p2, ctx->qwe->offset_x, ctx->qwe->offset_y);
		draw_line(ctx->img, p1->p1, p1->p2, 0x00FFFFFF);
	}
}

// Funzione per disegnare la linea verticale
void	draw_vertical_line(t_drawing_context *ctx, t_point_3 *p1, t_iter iter)
{
	if (ctx->mat->mat[iter.i + 1])
	{
		ft_start_point4(&p1->p3, iter, ctx->scale,
			ctx->mat->mat[iter.i + 1][iter.j]);
		iso_projection(&p1->p3.x, &p1->p3.y, p1->p3.z, ctx->qwe);
		ft_set(&p1->p3, ctx->qwe->offset_x, ctx->qwe->offset_y);
		draw_line(ctx->img, p1->p1, p1->p3, 0x00FFFFFF);
	}
}

// Funzione per calcolare la proiezione isometrica
void	iso_projection(int *x, int *y, int z, t_window *qwe)
{
	int	prev_x;
	int	prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(qwe->angle_x);
	*y = ((prev_x + prev_y) * sin(qwe->angle_y)) - z;
}

// Funzione principale per creare l'immagine
void	create_imagine(t_mat *mat, t_image img, t_window *qwe)
{
	t_iter				iter;
	t_point_3			p1;
	t_drawing_context	ctx;
	int					s;

	ctx.mat = mat;
	ctx.img = &img;
	ctx.qwe = qwe;
	iter.i = 0;
	while (mat->mat[iter.i])
	{
		iter.j = 0;
		while (iter.j < mat->x)
		{
			s = scale(qwe);
			ctx.scale = s;
			draw_current_point(&ctx, &p1, iter);
			draw_horizontal_l(&ctx, &p1, iter);
			draw_vertical_line(&ctx, &p1, iter);
			iter.j++;
		}
		iter.i++;
	}
}
