/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:42 by lhima             #+#    #+#             */
/*   Updated: 2025/01/31 15:55:10 by lhima            ###   ########.fr       */
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
		if(len == 0 && ft_atoi((*list)->num) > ft_atoi((*list)->next->next->num))
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
int sorted_move(t_lista **a)
{
	if(len_split(*a) == 2 && check_order(*a) == 1)
	{
		ft_printf("sa\n");
		swap_a(*a);
		ft_clean(*a, 0);
	}
	else if(len_split(*a) == 3)
	{
		ft_printf("%d\n", order_num_three(&(*a), 0));
		print_arr(*a);
		ft_clean(*a, 0);
	}
	if(len_split(*a) == 4)
	{
		ft_printf("%d\n",sorter_four(&(*a)));
		ft_clean(*a, 0);
	}

	return (0);
}
