/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:30:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s1:	The first string to compare.
s2:	The second string to compare.
n:	The number of bytes to compare.

DESCRIPTION
The memcmp() function compares the first n bytes (each interpreted as unsigned
char) of the memory areas s1 and s2.

RETURN VALUE
The memcmp() function returns an integer less than, equal to, or greater than
zero if the first n bytes of s1 is found, respectively, to be less than, to
match, or be greater than the first n bytes of s2.
For a nonzero return value, the sign is determined by the sign of the difference
between the first pair of bytes (interpreted as unsigned char) that differ in s1
and s2. If n is zero, the return value is zero.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	size_t			i;
	unsigned char	*s1_tmp;
	unsigned char	*s2_tmp;

	diff = 0;
	i = 0;
	s1_tmp = (unsigned char *) s1;
	s2_tmp = (unsigned char *) s2;
	while (i < n)
	{
		diff = (int)(s1_tmp[i] - s2_tmp[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	return (diff);
}
