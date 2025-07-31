/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrm_node.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 16:15:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/08 16:22:46 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"

/*
PARAMETERS
lst:		The address of a pointer to a node.
node_to_rm:	The node to be removed.
del:		The address of the function used to delete the content of the node.

DESCRIPTION
This function removes the node node_to_rm from the list e frees its allocated
memory using the function pointed to by del.
*/
void	ft_lstrmnode(t_list **lst, t_list *node_to_rm, void (*del)(void *))
{
	t_list	*curr;
	t_list	*prev;

	if (lst == NULL || *lst == NULL || node_to_rm == NULL)
		return ;
	curr = *lst;
	prev = NULL;
	while (curr != NULL)
	{
		if (curr == node_to_rm)
		{
			if (prev != NULL)
				prev->next = curr->next;
			else
				*lst = curr->next;
			ft_lstdelone(curr, del);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}
