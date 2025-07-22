/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:53:21 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
big:	The string to search little into.
little:	The string to find in big.
len:	The maximum number of bytes in which little is searched.

DESCRIPTION
The strnstr() function locates the first occurrence of the null-terminated
string little in the string big, where not more than len characters are
searched. Characters that appear after a ‘\0’ character are not searched.

RETURN VALUES
If little is an empty string, big is returned; if little occurs nowhere in 
big, NULL is returned; otherwise a pointer to the first character of the first
occurrence of little is returned.

EXAMPLES
The following sets the pointer ptr to NULL, because only the first 4 characters
of largestring are searched:
		const char *largestring = "Foo Bar Baz";
        const char *smallstring = "Bar";
		char *ptr;
		ptr = strnstr(largestring, smallstring, 4);
*/
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && little == NULL)
		return (NULL);
	if (*little == '\0' || big == little)
		return ((char *) big);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && \
			little[j] != '\0' && big[i + j] != '\0')
			j++;
		if (little[j] == '\0')
			return ((char *) &big[i]);
		i++;
	}
	return (NULL);
}
