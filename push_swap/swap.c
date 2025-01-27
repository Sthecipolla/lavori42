# include "push_swap.h"

int swap_a(char *arr)
{
	if(arr == NULL)
		return 0;
	return 1;
}

static int	len_split(char **arr)
{
	int x;

	x = 0;
	while(arr[x] != NULL)
		x++;
	return (x);
}
char **fill(char *arr)
{
	char **num;
	char *str;
	int i;

	i = 0;
	num = ft_split(arr, ' ');
	if(num == NULL)
		return 0;
	if(!num)
		return (NULL);
	return (num);
}
int	main(int argc, char **argv)
{
	char **str;

	str = fill(argv[1]);
	if(check(str) == 0 || argc == 1)
		return (0);
	if(swap_a(str) == 0)
		return (0);

}
