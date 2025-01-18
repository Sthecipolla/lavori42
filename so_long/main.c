/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:55 by lhima             #+#    #+#             */
/*   Updated: 2025/01/18 14:54:11 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_map	*prom;

	prom = ft_calloc(sizeof(t_map), 1);
	prom -> session = mlx_init();
	prom-> window = mlx_new_window(prom -> session, 1920, 1080, "bib bob");
	create_map(prom);
	ft_img_men(prom);
	mlx_key_hook (prom-> window,ft_input, prom);
	mlx_hook(prom-> window, 17, 0, ft_clean, prom);
	//mlx_loop_hook()
	mlx_loop(prom -> session);
}
