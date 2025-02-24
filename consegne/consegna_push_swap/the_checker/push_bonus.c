/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:26:54 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 16:26:35 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	push(t_lista **to_take, t_lista **to_add)
{
	t_lista	*tmp;

	if (*to_take == NULL)
		return ;
	tmp = *to_take;
	*to_take = (*to_take)->next;
	tmp->next = *to_add;
	*to_add = tmp;
}

void	cpush_a(t_lista **b, t_lista **a)
{
	push(b, a);
}

void	cpush_b(t_lista **a, t_lista **b)
{
	push(a, b);
}
