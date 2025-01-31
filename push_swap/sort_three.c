/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:31:07 by lhima             #+#    #+#             */
/*   Updated: 2025/01/31 18:51:59 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int order_num_three(t_lista **list, int i)
{
	int	len;

	len = check_order(*list);
	while(len != 3)
	{
		i ++;
		if(len == 0 && (*list)->num > (*list)->next->next->num)
		{
			ft_printf("ra\n");
			rotate_a(&(*list));
		}
		else if(len == 0)
		{
			ft_printf("sa\n");
			swap_a(*list);
		}
		else if(len == 2)
		{
			ft_printf("ra\n");
			rotate_a(&(*list));
		}
		else if(len == 1)
		{
			ft_printf("rra\n");
			reverse_a(&(*list));
		}
		len = check_order(*list);
	}
	return (i);
}

int before_three_sort(t_lista **a)
{
	if(check_order(*a) == 3)
		return (0);
	return (order_num_three(&(*a), 0));
}