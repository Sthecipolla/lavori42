/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:42 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 11:38:36 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int sorted_move(t_lista **a, t_lista **b)
{
	if((*a)->next->num < (*a)->num && len_split(*a) == 2)
		swap_a(*a);
	else if(len_split(*a) == 3)
	{
		before_three_sort(a);
		before_five_sort(a,b);
	}
	else
		before_sorting_num(a,b);
	ft_clean(*a, 0);
	return (0);
}
