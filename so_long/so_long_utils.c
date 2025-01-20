#include "so_long.h"

/* void print_map(char **map)
{
	int x;

	x = 0;
	while(map[x] != NULL)
		ft_printf("%s\n",(char *) map[x ++]);
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

int	ft_clean(t_map *s, int error)
{
	int i;

	i = -1;
	if(s -> imgarr[0].img)
	{
		while (s->imgarr[++i].img != NULL)
    		mlx_destroy_image(s->session, s->imgarr[i].img);
	}
	if(s -> window)
		mlx_destroy_window(s -> session, s -> window);
	if(s -> session)
		mlx_destroy_display(s -> session);
	free_double_pointer(s -> map);
	free(s -> session);
	free(s);
	if(error > 0)
		error= errorPrint(error);
	exit(error);
}
int	lenCol(char **map)
{
	int mxlenCol;

	mxlenCol = 0;
	while (map[mxlenCol] != NULL)
		mxlenCol++;
	return (mxlenCol);
}

char **create_a_copy_map(char **map)
{
    int rows;
	char **new_map;

	rows = 0;
    while (map[rows] != NULL)
        rows++;
    new_map = (char **)malloc((rows + 1) * sizeof(char *));
	if(!new_map)
	{
		free(new_map);
		return (NULL);
	}
	new_map[rows] = NULL;
	rows = 0;
	while(map[rows] != NULL)
	{
		new_map[rows] = ft_strdup(map[rows]);
		if(!new_map[rows])
		{
			free_double_pointer(new_map);
			return (NULL);
		}
		rows++;
	}
	return (new_map);
}

