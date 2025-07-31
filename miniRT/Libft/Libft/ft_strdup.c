/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:12:49 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	The string to duplicate.

DESCRIPTION
The strdup() function returns a pointer to a new string which is a duplicate
of the string s. Memory for the new string is obtained with malloc(3), and can
be freed with free(3).

RETURN VALUE
On success, the strdup() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available.
*/
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s);
	dest = (char *)malloc((s_len + 1) * sizeof(char ));
	if (dest == NULL)
		return (NULL);
	while (i < s_len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
