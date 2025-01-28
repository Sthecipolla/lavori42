/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:35:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 17:04:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

char **fill(char *arr)
{
	char **num;
	int i;

	i = 0;
	num = ft_split(arr, ' ');
	if(num == NULL)
		return 0;
	if(!num)
		return (NULL);
	return (num);
}
static void fill_struc(t_lista *t_lista, char **str)
{
	int i;

	i = 0;
	while(str[i] != NULL)
	{
		t_lista->num = str[i];
		t_lista->next = ft_calloc(sizeof(t_lista),1);
		t_lista = t_lista->next;
		i++;
	}
	t_lista->next = NULL;
	free_double_pointer(str);
}
int	main(int argc, char **argv)
{
	char **str;
	t_lista *t_lista;
	t_lista = ft_calloc(sizeof(t_lista),1);

	str = fill(argv[1]);
	//devo unire i valori se ci sono piu argomenti
	if(check(str) == 0 || argc == 1)
	{
		ft_printf("Error\narg\n");
		return (0);
	}
	fill_struc(t_lista, str);
	swap_a(t_lista);

	ft_clean(t_lista, 0);
	return (0);
}
