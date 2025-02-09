/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:31:07 by lhima             #+#    #+#             */
/*   Updated: 2025/02/01 14:42:00 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static int pre_check(t_lista **list, int len)
{
	if(len == 0 && (*list)->num > (*list)->next->next->num)
		{
			rotate_a(&(*list));
			return (1);
		}
	return (0);
}


static int order_num_three(t_lista **list, int i)
{

	while(check_order(*list)!= 3)
	{
		i ++;
		i+=pre_check(&(*list), check_order(*list));
		if(check_order(*list) == 3)
			break;
		if(check_order(*list) == 0)
			swap_a(*list);
		else if(check_order(*list)== 2)
			rotate_a(&(*list));
		else if(check_order(*list)== 1)

			reverse_a(&(*list));
	}
	return (i);
}

int before_three_sort(t_lista **a)
{
	if(check_order(*a) == 3)
		return (0);
	return (order_num_three(&(*a), 0));
}
