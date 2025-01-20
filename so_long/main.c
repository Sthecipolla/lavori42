/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:55 by lhima             #+#    #+#             */
/*   Updated: 2025/01/20 13:49:16 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_map	*prom;
	int	x;
	int y;

	y =-1;
	prom = ft_calloc(sizeof(t_map), 1);
	prom -> session = mlx_init();
	printf("%d", 1 + y);
	create_map(prom);
	x = lenCol(prom -> map) * 32;
	y = ft_strlen(prom -> map[0]) * 32;
	prom-> window = mlx_new_window(prom -> session,y, x, "bib bob");
	ft_img(prom);
	mlx_key_hook (prom-> window,ft_input, prom);
	mlx_hook(prom-> window, 17, 0, ft_clean, prom);
	//mlx_loop_hook()
	mlx_loop(prom -> session);
}
