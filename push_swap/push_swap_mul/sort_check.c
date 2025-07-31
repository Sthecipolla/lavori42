/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:42 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 15:50:33 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_move(t_lista **a, t_lista **b)
{
	if (len_split(*a) == 1)
		return (0);
	if ((*a)->next->num < (*a)->num && len_split(*a) == 2)
		swap_a(*a);
	else if (len_split(*a) == 3)
		before_three_sort(a);
	else
		before_sorting_num(a, b);
	ft_clean(*a, 0);
	return (0);
}
