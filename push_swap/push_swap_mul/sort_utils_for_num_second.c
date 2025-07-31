/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_for_num_second.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:34:30 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 15:52:39 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_distance(int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			return (cost_b - cost_a);
		return (cost_a - cost_b);
	}
	if (cost_b < 0)
		return (cost_a + cost_b);
	if (cost_a < 0)
		return ((cost_b + cost_a) * -1);
	if (cost_a > cost_b)
		return (cost_b - cost_a);
	return (cost_a - cost_b);
}

int	find_cost_of_a_num(t_lista *l, int num)
{
	t_lista	*tmp;

	tmp = l;
	while (tmp != NULL)
	{
		if (tmp->num == num)
			return (tmp->cost);
		tmp = tmp->next;
	}
	return (tmp->cost);
}

void	sort_stack_a(t_lista **a)
{
	t_lista	*tmp;
	int		cost;

	tmp = *a;
	while (tmp->num != find_min(*a))
		tmp = tmp->next;
	cost = tmp->cost;
	if (cost < 0)
	{
		while (cost++ != 0)
			reverse_a(a);
		return ;
	}
	while (cost-- != 0)
		rotate_a(a);
}
