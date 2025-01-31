/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:21:42 by lhima             #+#    #+#             */
/*   Updated: 2025/01/31 17:11:26 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"


int sorted_move(t_lista **a)
{
	if(len_split(*a) == 2 && check_order(*a) == 1)
	{
		ft_printf("sa\n");
		swap_a(*a);
	}
	else if(len_split(*a) == 3)
		ft_printf("%d\n", before_three_sort(&(*a)));
	else if(len_split(*a) == 4)
		ft_printf("%d\n",before_four_sort(&(*a)));
	else if(len_split(*a) == 5)
		ft_printf("%d\n",before_five_sort(&(*a)));

	print_arr(*a);
		ft_clean(*a, 0);
	return (0);
}
