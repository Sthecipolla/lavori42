/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:22:08 by lhima             #+#    #+#             */
/*   Updated: 2025/02/18 13:22:08 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "checker.h"

static void reverse_rotate(t_lista **list)
{
	t_lista *tmp;
	t_lista *tmp2;

	tmp = *list;
	tmp2 = *list;
	if(tmp == NULL || tmp->next == NULL)
		return ;
	while(tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *list;
	*list = tmp2;
}
void reverse_a(t_lista **list)
{
	reverse_rotate(list);
	ft_printf("rra\n");
}
void reverse_b(t_lista **list)
{
	reverse_rotate(list);
	ft_printf("rrb\n");
}
void reverse_rr(t_lista **a, t_lista **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
//porta in cima l'ultimo elemento della lista
