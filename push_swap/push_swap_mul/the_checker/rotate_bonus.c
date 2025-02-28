/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:22:54 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 16:26:41 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	rotate(t_lista **list)
{
	t_lista	*tmp;
	t_lista	*tmp2;

	if (*list == NULL || (*list)->next == NULL)
		return ;
	tmp = *list;
	tmp2 = *list;
	*list = (*list)->next;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	tmp->next = NULL;
}

void	crotate_a(t_lista **list)
{
	rotate(list);
}

void	crotate_b(t_lista **list)
{
	rotate(list);
}

void	crotate_rr(t_lista **a, t_lista **b)
{
	rotate(a);
	rotate(b);
}
