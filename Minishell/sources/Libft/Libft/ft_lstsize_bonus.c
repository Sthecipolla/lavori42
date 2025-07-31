/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:49:09 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
lst: The beginning of the list.

EXTERNAL FUNCTIONS
None

DESCRIPTION
Counts the number of nodes in a list.

RETURN VALUE
The length of the list.
*/
int	ft_lstsize(t_list *lst)
{
	int		length;

	length = 0;
	while (lst != NULL)
	{
		length++;
		lst = lst -> next;
	}
	return (length);
}
