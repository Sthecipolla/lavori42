# include "push_swap.h"

static int check_if_int_number(char **arr)
{
	int x;
	int y;

	x = 0;
	while(arr[x] != NULL)
	{
		y = 0;
		while(arr[x][y] != '\0')
		{
			if(arr[x][y] == '-' && y == 0 && arr[x][y] == '+')
				y++;
			if(ft_isdigit(arr[x][y]) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

static int check_max_value(char **arr)
{
	int x;

	x = 0;
	while(arr[x] != NULL)
	{
		if(ft_atoi(arr[x]) > 2147483647 || ft_atoi(arr[x]) < -2147483648)
			return (0);
		x++;
	}
	return (1);
}
static int check_duplicates(char **arr)
{
	int x;
	int y;

	x = 0;
	while(arr[x] != NULL)
	{
		y = x + 1;
		while(arr[y] != NULL)
		{
			if(ft_strcmp(arr[x], arr[y]) == 0)
				return (0);
			y++;
		}
		x++;
	}
	return (1);
}

int check(char **arr)
{
	if(check_if_int_number(arr) == 0)
		return (0);
	if(check_max_value(arr) == 0)
		return (0);
	if(check_duplicates(arr) == 0)
		return (0);
	return (1);
}
