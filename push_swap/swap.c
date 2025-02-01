/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:37 by lhima             #+#    #+#             */
/*   Updated: 2025/02/01 14:43:35 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

static void swap(t_lista *list)
{
	int t;

	if(list -> next == NULL || list == NULL)
		return;
	t = list->num;
	list->num = list->next->num;
	list->next->num = t;
}

void swap_a(t_lista *list)
{
	swap(list);
	ft_printf("sa\n");
}
void swap_b(t_lista *list)
{
	swap(list);
	ft_printf("sb\n");
}
void swap_ss(t_lista *list, t_lista *list2)
{
	swap_a(list);
	swap_b(list2);
	ft_printf("ss\n");
}
