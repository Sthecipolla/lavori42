/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:31:36 by daromoli          #+#    #+#             */
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
The strncmp() function compares the two strings s1 and s2.
The comparison is done using unsigned characters.

RETURN VALUE
It returns an integer less than, equal to, or greater than zero if the first n
bytes s1 is found, respectively, to be less than, to match, or be greater than
s2. That means, for the first n bytes:
-	0 if the s1 and s2 are equal;
-	a negative value if s1 is less than s2;
-	a positive value if s1 is greater than s2.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (i < n && s1[i] != '\0')
	{
		diff = (int)((unsigned char) s1[i] - (unsigned char) s2[i]);
		if (diff != 0)
			return (diff);
		i++;
	}
	if (i < n)
		diff = (int)((unsigned char) s1[i] - (unsigned char) s2[i]);
	return (diff);
}
