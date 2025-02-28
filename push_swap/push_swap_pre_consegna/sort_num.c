/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_num.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:31:16 by lhima             #+#    #+#             */
/*   Updated: 2025/02/11 12:32:04 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int sorting(t_lista **a, t_lista **b)
{
	while(len_split(*a) != 5)
	{
		push_b(a, b);
	}
	before_five_sort(a,b);
	add_cost(*a);
	add_cost(*b);
	while(len_split(*b) != 0)
	{
		find_num_cost(a, b);
		add_cost(*a);
		add_cost(*b);
	}
	sort_stack_a(a);
	return (1);
}

int before_sorting_num(t_lista **a,t_lista **b)
{
	if(check_order(*a) == len_split(*a))
		return (0);
	return (sorting(a,b));
}
