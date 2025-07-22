/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:53:04 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	The string to search c into.
c:	The character to be found.
n:	The number of bytes to check.

DESCRIPTION
The memchr() function scans the initial n bytes of the memory area pointed to
by s for the first instance of c. Both c and the bytes of the memory area 
pointed to by s are interpreted as unsigned char.

RETURN VALUE
The memchr() function returns a pointer to the matching byte or NULL if the
character does not occur in the given memory area.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s_tmp;

	i = 0;
	s_tmp = (unsigned char *) s;
	while (i < n)
	{
		if (*s_tmp == (unsigned char ) c)
			return ((void *) s_tmp);
		s_tmp++;
		i++;
	}
	return (NULL);
}
