/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:50:20 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/22 16:44:55 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS 
lst:	The address of a pointer to a node.
del:	The address of the function used to delete the content of the node.

EXTERNAL FUNCTIONS
free

DESCRIPTION
Deletes and frees the given node and every successor of that node, using the
function ’del’ and free(3).
Finally, the pointer to the list must be set to NULL.

RETURN VALUE
None.
*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst != NULL)
	{
		tmp = *lst;
		while (tmp != NULL)
		{
			tmp = (*lst)-> next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
	}
}
