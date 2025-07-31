/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:43:04 by daromoli          #+#    #+#             */
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
The memmove() function copies n bytes from memory area src to memory area dest.
The memory areas may overlap: copying takes place as though the bytes in src 
are first copied into a temporary array that does not overlap src or dest, and
the bytes are then copied from the temporary array to dest.

RETURN VALUE
The memmove() function returns a pointer to dest.

EXPLANATION
If src comes first and dest comes after (so dest > src), if I copy the bytes
from src to dest from the start of the two arrays I could overwrite the last
part of src before copying it to dest. So I need to copy them from the end.
If dest comes first and src comes after (so dest < src), I can copy the bytes
from the start, so I can use memcpy(3).
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	if (dest == NULL && src == NULL)
		return (NULL);
	dest_tmp = (unsigned char *) dest;
	src_tmp = (unsigned char *) src;
	if (dest > src && n > 0)
	{
		i = n;
		while (i > 0)
		{
			dest_tmp[i - 1] = src_tmp[i - 1];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
