/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:26 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 16:26:38 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	reverse_rotate(t_lista **list)
{
	t_lista	*tmp;
	t_lista	*tmp2;

	tmp = *list;
	tmp2 = *list;
	if (tmp == NULL || tmp->next == NULL)
		return ;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *list;
	*list = tmp2;
}

void	creverse_a(t_lista **list)
{
	reverse_rotate(list);
}

void	creverse_b(t_lista **list)
{
	reverse_rotate(list);
}

void	creverse_rr(t_lista **a, t_lista **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
