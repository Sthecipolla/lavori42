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
