/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:18:43 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	the memory area to erase.
n:	number of bytes to erase.

DESCRIPTION
The bzero() function erases the data in the n bytes of the memory starting at
the location pointed to by s, by writing zeros (bytes containing '\0') to that
area.

RETURN VALUE
None.
*/
void	ft_bzero(void *s, size_t n)
{
	char	*s_tmp;
	size_t	i;

	i = 0;
	s_tmp = (char *) s;
	while (i < n)
	{
		s_tmp[i] = '\0';
		i++;
	}
}
