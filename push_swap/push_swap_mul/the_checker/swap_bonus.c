/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:37 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 16:26:43 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static void	swap(t_lista *list)
{
	int	t;

	if (list == NULL || list->next == NULL)
		return ;
	t = list->num;
	list->num = list->next->num;
	list->next->num = t;
}

void	cswap_a(t_lista *list)
{
	swap(list);
}

void	cswap_b(t_lista *list)
{
	swap(list);
}

void	cswap_ss(t_lista *list, t_lista *list2)
{
	swap_a(list);
	swap_b(list2);
}
