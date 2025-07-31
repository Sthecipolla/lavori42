/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:29:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS 
lst: The address of a pointer to the first link of a list.
new: The address of a pointer to the node to be added to the list.

EXTERNAL FUNCTIONS
None

DESCRIPTION
Adds the node ’new’ at the end of the list.

RETURN VALUE
None.
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst != NULL && new != NULL)
	{
		if (*lst != NULL)
			ft_lstlast(*lst)-> next = new;
		else
			*lst = new;
	}
}
