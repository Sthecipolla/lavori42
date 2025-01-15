#include "so_long.h"

void	check_map(char **map)
{
	int border;
/* 	int portal;
	int player;
	int coin; */

	border = check_border(map);
	/* portal = 0;
	player;
	coin; */
	if(border == 0)
		exit(1);
}

