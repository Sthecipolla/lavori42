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
void	create_map(t_map *map)
{
	char *str;
	int	x;
	int fd;

	x = 0;
	fd = open("text.txt",O_RDONLY ,777);
	str = calloc(1,1);
	while(str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		x++;
	}
	x = 0;
	str = calloc(1,1);
	map -> map =  (char **)ft_calloc(x + 1, sizeof(char*));
	while(str != NULL)
	{
		free(str);
		map -> map[x++] = get_next_line(fd);
	}
}
int	main(void)
{
	t_map	*prom;
	//t_data	img;
	//t_win_list	vars;
	int	x;

	prom = ft_calloc(sizeof(t_map), 1);
	prom -> session = mlx_init();
	prom-> window = mlx_new_window(prom -> session, 1920, 1080, "bib bob");
	x = mlx_key_hook (prom-> window,input_men, &prom);
	mlx_loop(prom -> session);
}
