#include "so_long.h"

int other_input(int key_sim, t_map *s)
{
	if(key_sim == XK_1 && !s)
		return (1);
	return(0);
}

int	ft_input(int key_sim, t_map *s)
{
	if(key_sim == XK_Escape)
		ft_clean(s, 0);
	if(key_sim == XK_w)
		ft_printf("su\n");
	if(key_sim == XK_s)
		ft_printf("giu\n");
	if(key_sim == XK_d)
		ft_printf("destra\n");
	if(key_sim == XK_a)
		ft_printf("sinistra\n");


	return (0);
}

