/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:54 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:46:56 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	scale(t_window *qwe)
{
	if (qwe->zoom < 1)
		return (1);
	return (qwe->zoom);
}

void	ft_start_point(t_point *p, int x, int y, int z)
{
	p->x = x;
	p->y = y;
	p->z = z;
}

void	ft_start_point2(t_point *p, t_iter iter, int s, int mat)
{
	p->x = iter.j * s;
	p->y = iter.i * s;
	p->z = mat;
}

void	ft_start_point3(t_point *p, t_iter iter, int s, int mat)
{
	iter.j++;
	p->x = iter.j * s;
	p->y = iter.i * s;
	p->z = mat;
}

void	ft_start_point4(t_point *p, t_iter iter, int s, int mat)
{
	iter.i++;
	p->x = iter.j * s;
	p->y = iter.i * s;
	p->z = mat;
}
