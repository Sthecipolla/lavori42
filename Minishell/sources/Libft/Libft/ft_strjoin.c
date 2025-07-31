/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:32:01 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PAREMETERS 
s1: The prefix string.
s2: The suffix string.

EXTERNAL FUNCTIONS 
malloc

DESCRIPTION
Allocates (with malloc(3)) and returns a new string, which is the result of the
concatenation of ’s1’ and ’s2’.

RETURN VALUE
The new string. NULL if the allocation fails.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_joined;
	size_t	l1;
	size_t	l2;
	size_t	i;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s_joined = (char *) malloc((l1 + l2 + 1) * sizeof(char));
	if (s_joined == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		s_joined[i] = s1[i];
		i++;
	}
	while (s2[i - l1] != '\0')
	{
		s_joined[i] = s2[i - l1];
		i++;
	}
	s_joined[i] = '\0';
	return (s_joined);
}
