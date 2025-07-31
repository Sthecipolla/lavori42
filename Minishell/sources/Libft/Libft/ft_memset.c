/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:40:23 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	The memory area to overwrite with c.
c:	The costant byte to write in s.
n:	The number of bytes to write.

DESCRIPTION
The memset() function fills the first n bytes of the memory area pointed to by
s with the constant byte c.

RETURN VALUE
The memset() function returns a pointer to the memory area s.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_tmp;
	size_t			i;

	i = 0;
	s_tmp = (unsigned char *) s;
	while (i < n)
	{
		s_tmp[i] = (unsigned char) c;
		i++;
	}
	return (s);
}
