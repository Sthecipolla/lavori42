/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_menag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:12 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 14:48:47 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	other_input(t_map *prom,int y, int x)
{
	if (prom->map[y][x] == 'T')
	{
		ft_printf("perso :(\n");
		ft_clean(prom, 0);
	}
	prom->map[y][x] = 'P';
	ft_img(prom);
	return (0);
}

static int	calc_position(t_map *prom, int move_x, int move_y)
{
	int			x;
	int			y;
	static int	move;

	y = check_pos_player(prom->map, 0);
	x = check_pos_player(prom->map, 1);
	if (prom->map[y + move_y][x + move_x] == '1')
		return (2);
	if (prom->map[y + move_y][x + move_x] == 'E' &&
		prom->coins != prom->tot_coins)
		return (2);
	if (prom->map[y + move_y][x + move_x] == 'E' &&
		prom->coins == prom->tot_coins)
		ft_clean(prom, 0);
	move++;
	if (prom->map[y + move_y][x + move_x] == 'C')
		prom->coins++;
	ft_printf("move: %d\n", move);
	prom->map[y][x] = '0';
	other_input(prom, y + move_y, x + move_x);
	return (0);
}

int	ft_input(int key_sim, t_map *s)
{
	if (key_sim == XK_Escape)
		ft_clean(s, 0);
	if (key_sim == XK_w)
		calc_position(s, 0, -1);
	if (key_sim == XK_s)
		calc_position(s, 0, 1);
	if (key_sim == XK_d)
		calc_position(s, 1, 0);
	if (key_sim == XK_a)
		calc_position(s, -1, 0);
	return (0);
}
