/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:09:54 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
dest:	The destination string. I want to concatenate src to this.
src:	The source string.
size:	The size of the string I want to create, including the null-terminating
		character.

DESCRIPTION
The strlcat() function concatenate strings. strlcat() takes the full size of
the buffer (not just the length) and guarantee to NUL-terminate the result (as
long as size is larger than 0 or as long as there is at least one byte free in
dst). Note that a byte for the NUL should be included in size. Also note that
for strlcat() both src and dst must be NUL-terminated.

RETURN VALUE
The strlcat() function return the total length of the string it tried to crea-
te. For strlcat() that means the initial length of dst plus the length of src.
*/
size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	i;
	size_t	length;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	i = dest_len;
	if (size <= dest_len)
		length = src_len + size;
	else
	{
		while (i < (size - 1) && src[i - dest_len] != '\0')
		{
			dest[i] = src[i - dest_len];
			i++;
		}
		dest[i] = '\0';
		length = src_len + dest_len;
	}
	return (length);
}
