/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:34:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
dest:	The memory area of destination.
src:	The source memory area.
n:		The number of bytes to copy.

DESCRIPTION
The memcpy() function copies n bytes from memory area src to memory area dest.
The memory areas must notoverlap. Use memmove(3) if the memory areas overlap.

RETURN VALUE
The memcpy() function returns a pointer to dest.
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	while (i < n)
	{
		dest_tmp[i] = src_tmp[i];
		i++;
	}
	return (dest);
}
