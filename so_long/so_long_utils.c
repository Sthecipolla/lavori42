#include "so_long.h"

/* void print_map(char **map)
{
	int x;

	x = 0;
	while(map[x] != NULL)
		ft_printf("%s",(char *) map[x ++]);
} */

void free_double_pointer(char **ptr)
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
static	int errorPrint(int	error)
{
	if(error == 11)
		ft_printf("error\n map\n");
	return(0);
}
int	ft_clean(t_map *s, int error)
{
		mlx_destroy_window(s -> session, s -> window);
		mlx_destroy_display(s -> session);
		free_double_pointer(s -> map);
		free(s -> session);
		free(s);
		if(error > 0)
			error= errorPrint(error);
		exit(error);
}

