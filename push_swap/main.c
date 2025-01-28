/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:35:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 17:50:08 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

char **fill(char *arr)
{
	char **num;
	num = ft_split(arr, ' ');
	if(num == NULL)
		return 0;
	if(!num)
		return (NULL);
	return (num);
}
static void fill_struc(t_lista *list, char **str)
{
	int i;

	i = 0;
	while(str[i] != NULL)
	{
		list->num = ft_strdup(str[i]);
		if(str[i + 1] == NULL)
			break;
		list->next = ft_calloc(sizeof(t_lista),1);
		list = list->next;
		i++;
	}
	list->next = NULL;
	free_double_pointer(str);
}
int	main(int argc, char **argv)
{
	char **str;
	t_lista *list;

	str = fill(argv[1]);
	//devo unire i valori se ci sono piu argomenti
	if(check(str) == 0 || argc == 1)
	{
		ft_printf("Error\narg\n");
		return (0);
	}
	list = ft_calloc(sizeof(t_lista),1);
	fill_struc(list, str);
	swap_a(list);
	ft_clean(list, 0);
	return (0);
}
