#include "so_long.h"


static int	check_wall_all_alline(char **map)
{
	int col;
	int index;
	int app;

	col = ft_strlen(map[0]);
	index = 0;
	while(map[index]!=NULL)
	{
		app = (int)ft_strlen(map[index]);
		if(app != col)
			return (0);
		index++;
	}
	return (1);
}


static	int check_border_are_all_close(char **map)
{
	int col;
	int linee;
	int mxlenCol;
	int mxlenLinee;

	mxlenLinee = lenCol(map) - 1 ;
	mxlenCol = ft_strlen(map[0]) - 1;

	col = -1;
	while (++col <= mxlenCol)
	{
		if (map[0][col] != '1' || map[mxlenLinee][col] != '1')
			return (0);
	}
	linee = -1;
	while (++linee <= mxlenLinee)
	{
		if (map[linee][0] != '1' || map[linee][mxlenCol] != '1')
			return (0);
	}
	return (1);
}

int check_border(char **map)
{
	if(check_wall_all_alline(map)== 0)
		return (0);
	if(check_border_are_all_close(map) == 0)
		return(0);
	return (1);
}
