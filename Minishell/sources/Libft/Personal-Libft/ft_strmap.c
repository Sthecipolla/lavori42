/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:22:41 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/01 11:33:51 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"

/*
PARAMETERS
s:	The string to duplicate.
f:	A pointer to a function to 

DESCRIPTION
This function returns a pointer to a new string which is a duplicate of the
string s. Before the duplication, the function f is applied to every character
in s. Memory for the new string is obtained with malloc(3), and can be freed
with free(3).

RETURN VALUE
On success, the ft_strmap() function returns a pointer to the duplicated string.
It returns NULL if insufficient memory was available.
*/
char	*ft_strmap(const char *s, int (*f)(int))
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
		dest[i] = (*f)(s[i]);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
