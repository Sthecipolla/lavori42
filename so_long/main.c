/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:13:55 by lhima             #+#    #+#             */
/*   Updated: 2025/01/14 16:16:23 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* static int	f_close(int keycode, t_xvar *vars)
{
	if(keycode == 0)
		return (0);
	mlx_destroy_window(vars->mlx, vars->window);
	return (0);
} */
void	create_map(t_map *map)
{
	char *str;
	int	x;
	int fd;
	int y;

	x = 0;
	y = -1;
	fd = open("text.txt",O_RDONLY ,777);
	str = ft_calloc(1,1);
	while(str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		x++;
	}
	str = ft_calloc(1,1);
	map -> map =  (void **)ft_calloc(x + 1, sizeof(char*));
	while(++y < x)
		map -> map[x++] = get_next_line(fd);
}

int other_input(int key_sim, t_map *s)
{
	if(key_sim == XK_1 && !s)
		return (1);
	return(0);
}
int	input_men(int key_sim, t_map **s)
{
	if(key_sim == XK_Escape)
	{
		mlx_destroy_window((*s) -> session, (*s)-> window);
		mlx_destroy_display((*s) -> session);
		free((*s));
		exit(0);
	}
	return (other_input(key_sim, (*s)));
}

int	main(void)
{
	t_map	*prom;
	//t_data	img;
	//t_win_list	vars;

	prom = ft_calloc(sizeof(t_map), 1);
	prom -> session = mlx_init();
	prom-> window = mlx_new_window(prom -> session, 1920, 1080, "bib bob");
	mlx_key_hook (prom-> window,input_men, &prom);
	mlx_loop(prom -> session);
}
