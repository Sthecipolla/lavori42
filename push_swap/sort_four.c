/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:48 by lhima             #+#    #+#             */
/*   Updated: 2025/01/31 16:49:33 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int check_if_last(t_lista **a)
{
	t_lista *tmp;

	tmp = *a;
	while(tmp->next != NULL)
		tmp = tmp->next;
	if(ft_atoi(tmp->num) == find_min(*a))
	{
		ft_printf("rra\n");
		reverse_a(&(*a));
		return (1);
	}
	return (0);
}

int sorter_four(t_lista **a)
{
	t_lista *b;
	int i;

	i = 0;
	while(len_split((*a)) != 3)
	{
		i++;
		check_if_last(&(*a));
		if(ft_atoi((*a)->num) == find_min((*a)))
		{
			ft_printf("pb\n");
			push_b(&(*a), &b);
		}
		else
		{
			ft_printf("ra\n");
			rotate_a(&(*a));
		}
	}
	i+=order_num_three(&(*a), 0);
	push_a(&b, &(*a));
	ft_printf("pa\n");
	i++;
	print_arr(*a);
	return (i);
}
