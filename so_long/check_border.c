#include "so_long.h"

static int	lenCol(char **map)
{
	int mxlenCol;

	mxlenCol = 0;
	while (map[mxlenCol] != NULL)
		mxlenCol++;
	return (mxlenCol);
}
static int	check_wall_all_alline(char **map)
{
	int col;
	int index;

	col = ft_strlen(map[0]);
	index = 0;
	while(map[index]!=NULL)
	{
		if((int)ft_strlen(map[index])!=col)
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

	mxlenCol = lenCol(map);
	mxlenLinee = ft_strlen(map[0]);
	
	linee = -1;
	while (map[++linee] != NULL)
	{
		if (map[linee][0] != '1' || map[linee][mxlenCol] != '1')
			return (0);
	}
	col = -1;
	while (map[++col] != NULL)
	{
		if (map[0][col] != '1' || map[mxlenLinee][col] != '1')
			return (0);
	}
	return (1);
}

int check_border(char **map)
{
	if( check_border_are_all_close(map) == 0)
		exit(10);
	if(check_wall_all_alline(map)== 0)
		exit(12);
	return (1);
}
