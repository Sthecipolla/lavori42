/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:37 by lhima             #+#    #+#             */
/*   Updated: 2025/01/31 10:06:48 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void swap_a(t_lista *list)
{
	if(list -> next == NULL || list == NULL)
		return;

	char *t;
	t = list->num;
	list->num = list->next->num;
	list->next->num = t;
}
void swap_b(t_lista *list)
{
	swap_a(list);
}
void swap_ss(t_lista *list, t_lista *list2)
{
	swap_a(list);
	swap_b(list2);
}
