/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 10:57:13 by lhima             #+#    #+#             */
/*   Updated: 2025/02/13 10:57:21 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argn, char **argc)
{
	t_map	*prom;
	int		x;
	int		y;

	if (argn != 2 || !check_file_valid(argc[1]))
	{
		ft_printf("Error\nargument\n");
		return (0);
	}
	prom = ft_calloc(sizeof(t_map), 1);
	if (!prom)
		return (0);
	prom->session = mlx_init();
	create_map(prom, argc[1]);
	x = len_col(prom->map) * 32;
	y = ft_strlen(prom->map[0]) * 32;
	prom->window = mlx_new_window(prom->session, y, x, "bib bob");
	ft_img(prom);
	//mlx_hook(prom->window, 2, 1L << 0, ft_input, prom);
	mlx_hook(prom->window, 17, 0, ft_clean, prom);
	mlx_loop(prom->session);
	return (0);
}
