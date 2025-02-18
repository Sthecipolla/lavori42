# include "checker.h"
int check_order(t_lista *l)
{
	t_lista *tmp;
	int		i;

	i = 0;
	tmp = l;
	while(tmp->next != NULL)
	{
		if(tmp->num > tmp->next->num)
			return (i);
		tmp = tmp->next;
		i ++;
	}
	return (i + 1);
}

int	check_move(char *line, t_lista **a, t_lista **b)
{
	if(ft_strncmp(line, "sa", 2) == 0)
		sa(a);
	else if(ft_strncmp(line, "sb", 2) == 0)
		sb(b);
	else if(ft_strncmp(line, "ss", 2) == 0)
		ss(a, b);
	else if(ft_strncmp(line, "pa", 2) == 0)
		pa(a, b);
	else if(ft_strncmp(line, "pb", 2) == 0)
		pb(a, b);
	else if(ft_strncmp(line, "ra", 2) == 0)
		ra(a);
	else if(ft_strncmp(line, "rb", 2) == 0)
		rb(b);
	else if(ft_strncmp(line, "rr", 2) == 0)
		rr(a, b);
	else if(ft_strncmp(line, "rra", 3) == 0)
		rra(a);
	else if(strncmp(line, "rrb", 3) == 0)
		rrb(b);
	else if(ft_strncmp(line,"rrr",3) == 0)
		rrr(a, b);
	else
		return (1);
	return (0);
}

char **fill(char **arr)
{
	char	**num;
	char	*str;
	char	*app;
	int		i;

	i = 1;
	str = ft_strjoin(arr[i++], "");
	while(arr[i])
	{
		app = str;
		str = ft_strjoin(str, " ");
		free(app);
		app = str;
		str = ft_strjoin(str, arr[i]);
		free(app);
		i++;
	}
	num = ft_split(str, ' ');
	free(str);
	if(num == NULL)
		return 0;
	if(!num)
		return (NULL);
	return (num);
}

void fill_struc(t_lista *list, char **str)
{
	int i;
	char *c;


	i = 0;
	while(str[i] != NULL)
	{
		c = ft_strdup(str[i]);
		list->num = ft_atoi(c);
		free(c);
		if(str[i + 1] == NULL)
			break;
		list->next = ft_calloc(sizeof(t_lista),1);
		list = list->next;
		i++;
	}
	list->next = NULL;
	free_double_pointer(str);
}
