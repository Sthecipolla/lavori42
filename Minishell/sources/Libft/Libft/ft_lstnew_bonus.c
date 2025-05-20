/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:31:27 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
content: The content to create the node with.

EXTERNAL FUNCTIONS
malloc

DESCRIPTION
Allocates (with malloc(3)) and returns a new node.
The member variable ’content’ is initialized with the value of the parameter
’content’. The variable ’next’ is initialized to NULL.

RETURN VALUE
The new node.
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*newnode;

	newnode = (t_list *) malloc(sizeof(t_list));
	if (newnode == NULL)
		return (NULL);
	newnode -> content = content;
	newnode -> next = NULL;
	return (newnode);
}
