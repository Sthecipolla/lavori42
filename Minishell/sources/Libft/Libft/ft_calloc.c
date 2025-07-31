/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:32:05 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
nmemb:	number of elements that I need to allocate.
size:	size in bytes of a single element.

DESCRIPTION
The calloc() function allocates memory for an array of nmemb elements of size
bytes each and returns a pointer to the allocated memory. The memory is set to
zero. If nmemb or size is 0, then calloc() returns either NULL, or a unique
pointer value that can later be successfully passed to free().
If the multiplication of nmemb and size would result in integer overflow, then
calloc() returns an error (NULL). By contrast, an integer overflow would not be 
detected in the following call to malloc(), with the result that an incorrectly
sized block of memory would be allocated:
	malloc(nmemb * size);

RETURN VALUE
The calloc() functions return a pointer to the allocated memory, which is
suitably aligned for any built-in type.
On error, this function return NULL. NULL may also be returned by a successful
call to calloc() with nmemb or size equal to zero.

EXPLANATION
If nmemb is 0 or size is 0, I need to call malloc and the error comes from it.
So I must not return NULL if nmemb is 0 or size is 0, but malloc(0). I Still
need to check for integer overflow, so the first check is for that.
*/
void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		total_size;
	size_t		size_max;

	size_max = (size_t)(-1);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (size != 0 && nmemb > (size_max / size))
		return (NULL);
	total_size = nmemb * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}
