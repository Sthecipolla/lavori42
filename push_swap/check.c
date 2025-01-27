# include "push_swap.h"
static check_if_number(char **arr)
{
	int x;
	int y;

	x = 0;
	while(arr[x] != NULL)
	{
		y = 0;
		while(arr[x][y] != '\0')
		{
			if(ft_isdigit(arr[x][y]) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}
int check(char **arr)
{

	{
		if(ft_atoi(arr) > 2147483647 || ft_atoi(arr) < -2147483648)
			return 0;
		arr++;
	}

	return 1;
}
