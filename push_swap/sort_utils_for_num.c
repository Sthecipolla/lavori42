/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_for_num.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:03:35 by lhima             #+#    #+#             */
/*   Updated: 2025/02/03 17:11:01 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void search_topalf_for_min(t_lista **a, t_lista **b)
{
	t_lista *tmp;
	int i;
	int j;

	i = 0;
	j = 0;
	tmp = *a;
	while(tmp->next != NULL)
	{
		if(tmp->num == find_min(*a))
			break;
		tmp = tmp->next;
		i++;
	}
	if(i < len_split(*a) / 2)
	{
		while(j < i)
		{
			rotate_a(a);
			j++;
		}
	}
	else
	{
		while(j < len_split(*a) - i)
		{
			reverse_a(a);
			j++;
		}
	}
	push_b(a,b);

}
