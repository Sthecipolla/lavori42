/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:31:16 by lhima             #+#    #+#             */
/*   Updated: 2025/02/03 18:32:42 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* static int check_if_last(t_lista **a)
{
	t_lista *tmp;

	tmp = *a;
	while(tmp->next != NULL)
		tmp = tmp->next;
	if(tmp->num == find_min(*a))
	{
		ft_printf("rra\n");
		reverse_a(&(*a));
		return (1);
	}
	return (0);
} */

static int sorting(t_lista **a, t_lista **b)
{
	while(len_split(*a) != 5)
	{
		search_topalf_for_min(a,b);
	}
	before_five_sort(a,b);
	while((*b) != NULL)
		push_a(b, a);
	return (1);
}

int before_sorting_num(t_lista **a,t_lista **b)
{
	if(check_order(*a) == len_split(*a))
		return (0);
	return (sorting(a,b));
}
