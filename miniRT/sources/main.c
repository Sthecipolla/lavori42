/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:21:34 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:21:38 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

int	main(int argc, char **argv)
{
	t_data	*data;

	data = ft_init_data(argc, argv);
	if (data == NULL)
		return (errno);
	ft_render(data);
	mlx_loop(data->mlx->mlx_session);
	ft_cleanup(data);
	return (EXIT_SUCCESS);
}
