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

/* void print_map(char ***map)
{
	int x;

	x = 0;
	while((*map)[x] != NULL)
		ft_printf("%s",(char *) (*map)[x ++]);
} */
void	create_map(t_map **map)
{
	char *str;
	int	x;
	int fd;
	int y;

	x = 0;
	y = -1;
	fd = open("text.txt",O_RDONLY ,777);
	if (fd < 0)
        exit(fd);
	str = ft_calloc(1,1);
	while(str != NULL)
	{
		free(str);
		str = get_next_line(fd);
		x++;
	}
	close(fd);
	fd = open("text.txt",O_RDONLY ,777);
	if (fd < 0)
        exit(fd);
	(*map) -> map =  (char **)malloc(x * sizeof(char*));
	while(++y < x - 1)
		(*map) -> map[y] = get_next_line(fd);
	(*map) -> map[y] = NULL;
}

int other_input(int key_sim, t_map *s)
{
	if(key_sim == XK_1 && !s)
		return (1);
	return(0);
}
static void free_double_pointer(char **ptr)
{
    int i = 0;

    if (ptr == NULL)
        return;

    while (ptr[i] != NULL)
    {
        free(ptr[i]);
        i++;
    }
    free(ptr);
}
int	input_men(int key_sim, t_map **s)
{
	if(key_sim == XK_Escape)
	{
		mlx_destroy_window((*s) -> session, (*s)-> window);
		mlx_destroy_display((*s) -> session);
		free_double_pointer((*s) -> map);
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
	create_map(&prom);
	//print_map(&prom -> map);
	//check_map(prom -> map);
	prom-> window = mlx_new_window(prom -> session, 1920, 1080, "bib bob");
	mlx_key_hook (prom-> window,input_men, &prom);
	mlx_loop(prom -> session);
}
