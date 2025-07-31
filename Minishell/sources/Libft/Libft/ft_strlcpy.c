/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:02:05 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
dest:	The string to copy src into.
src:	The source string.
size:	The number of characters to copy, including the null-terminating char.

DESCRIPTION
The strlcpy() function copy strings. strlcpy() takes the full size of the
buffer (not just the length) and guarantee to NUL-terminate the result (as
long as size is larger than 0). Note that a byte for the NUL should be
included in size. Also note that for strlcpy() src must be NUL-terminated.

RETURN VALUE
The strlcpy() function return the total length of the string it tried to 
create. For strlcpy() that means the length of src.
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;

	i = 0;
	length = ft_strlen(src);
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (length);
}
