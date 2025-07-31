/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_2link.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:49:59 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:50:00 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_start_2link(t_stack **lst)
{
	t_stack	*current;

	current = *lst;
	while (current)
	{
		if (current->next)
			current->next->prev = current;
		current = current->next;
	}
}
