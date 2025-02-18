/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:03 by lhima             #+#    #+#             */
/*   Updated: 2025/02/18 13:22:04 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "checker.h"

static void push(t_lista **to_take, t_lista **to_add)
{
	t_lista *tmp;

	if(*to_take == NULL)
		return;
	tmp = *to_take;
	*to_take = (*to_take)->next;
	tmp->next = *to_add;
	*to_add = tmp;
}
void push_a(t_lista **b, t_lista **a)
{
	push(b, a);
	ft_printf("pa\n");
}
void push_b(t_lista **a, t_lista **b)
{
	push(a, b);
	ft_printf("pb\n");
}
