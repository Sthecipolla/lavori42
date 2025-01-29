/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:35:08 by lhima             #+#    #+#             */
/*   Updated: 2025/01/29 17:54:34 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int	main(int argc, char **argv)
{
	char **str;
	t_lista *list;
	t_lista *b;
	int len;
	int i;

	i = 0;
	if(argc == 1)
	{
		ft_printf("Error\nno arg\n");
		return (0);
	}
	str = fill(argv);
	check(str);
	list = ft_calloc(sizeof(t_lista),1);
	b = NULL;
	fill_struc(list, str);
	len = check_order(list);
	while(len != len_split(list))
	{
		i ++;
		if(len_split(list) == 1)
			break;
		if(len_split(list) == 2)
		{
			swap_a(list);
			break;
		}
		if(len_split(list) == 3)
		{
			if(len == 0)
				swap_a(list);
			else if(len == 2)
				rotate_a(&list);
			else if(len == 1)
				reverse_a(&list);
		}
		if(len_split(list) == 4)
		{
			if(len == 0)
				swap_a(list);
			else if(len == 3)
				reverse_a(&list);
			else if(len == 1)
				reverse_a(&list);
		}
		len = check_order(list);
		print_arr(list);
	}
	printf("move: %d\n", i);
	ft_clean(list, 100);
	ft_clean(b, 0);
	return (i);
}
