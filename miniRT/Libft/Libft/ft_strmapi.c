/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:39:23 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
s:	The string on which to iterate.
f:	The function to apply to each character.

EXTERNAL FUNCTIONS
malloc

DESCRIPTION
Applies the function f to each character of the string s, passing its index as
the first argument and the character itself as the second.
A new string is created (using malloc(3)) to collect the results from the
successive applications of f.

RETURN VALUE
The string created from the successive applications of ’f’.
Returns NULL if the allocation fails.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	i;
	char	*s_f;

	s_len = ft_strlen(s);
	s_f = (char *) malloc((s_len + 1) * sizeof(char));
	if (s_f == NULL)
		return (NULL);
	i = 0;
	while (i < s_len)
	{
		s_f[i] = f(i, s[i]);
		i++;
	}
	s_f[i] = '\0';
	return (s_f);
}
