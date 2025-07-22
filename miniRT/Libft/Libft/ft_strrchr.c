/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:14:22 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	The string to search c into.
c:	The character to find.

DESCRIPTION
The strrchr() function returns a pointer to the last occurrence of the 
character c in the string s.
Here "character" means "byte"; these functions do not work with wide or
multibyte characters.

RETURN VALUE
The strrchr() function returns a pointer to the matched character or NULL if
the character is not found. The terminating null byte is considered part of
the string, so that if c is specified as '\0', this function returns a pointer
to the terminator.
*/
char	*ft_strrchr(const char *s, int c)
{
	char	*s_tmp;

	s_tmp = (char *) s;
	while (*s_tmp != '\0')
		s_tmp++;
	while (s_tmp >= s)
	{
		if (*s_tmp == (char ) c)
			return (s_tmp);
		s_tmp--;
	}
	return (NULL);
}
