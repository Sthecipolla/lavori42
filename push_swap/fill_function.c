# include "push_swap.h"

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

void add_cost(t_lista *list)
{
	t_lista *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = list;
	while(tmp)
	{
		if(len_split(list)/2 < i)
		{
			tmp->cost = (len_split(list) - i) * -1;
			i++;
		}
		else
			tmp->cost = i++;
		tmp = tmp->next;
	}
}
