/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:48 by lhima             #+#    #+#             */
/*   Updated: 2025/02/01 14:41:43 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_if_last(t_lista **a)
{
	t_lista	*tmp;

	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	if (tmp->num == find_min(*a))
	{
		reverse_a(&(*a));
		return (1);
	}
	return (0);
}

static int	sorter_four(t_lista **a, t_lista **b)
{
	int	i;

	i = 0;
	while (len_split((*a)) != 3)
	{
		i++;
		i += check_if_last(&(*a));
		if ((*a)->num == find_min((*a)))
			push_b(&(*a), &(*b));
		else
			rotate_a(&(*a));
	}
	i += before_three_sort(&(*a));
	push_a(b, a);
	i++;
	return (i);
}

int	before_four_sort(t_lista **a, t_lista **b)
{
	if (check_order(*a) == 4)
		return (0);
	return (sorter_four(a, b));
}
