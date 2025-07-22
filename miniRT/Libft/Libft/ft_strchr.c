/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 07:40:46 by daromoli          #+#    #+#             */
/*   Updated: 2024/11/20 07:40:46 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	The string to search c into.
c:	The character to find.

DESCRIPTION
The strchr() function returns a pointer to the first occurrence of the
character c in the string s.
Here "character" means "byte"; this function does not work with wide or 
multibyte characters.

RETURN VALUE
The strchr() function returns a pointer to the matched character or NULL if 
the character is not found. The terminating null byte is considered part of
the string, so that if c is specified as '\0', this function returns a pointer
to the terminator.
*/
char	*ft_strchr(const char *s, int c)
{
	char	*s_tmp;

	s_tmp = (char *) s;
	while (*s_tmp != '\0')
	{
		if (*s_tmp == (char) c)
			return (s_tmp);
		s_tmp++;
	}
	if (*s_tmp == (char) c)
		return (s_tmp);
	return (NULL);
}
