/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:57:34 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

static int		ft_isinset(char c, char const *set);
static size_t	ft_trimmed_len(const char *s1, char const *set);

/*
PARAMETERS 
s1:		The string to be trimmed.
set:	The reference set of characters to trim.

EXTERNAL FUNCTIONS
malloc

DESCRIPTION
Allocates (with malloc(3)) and returns a copy of ’s1’ with the characters
specified in ’set’ removed from the beginning and the end of the string.

RETURN VALUE
The trimmed string. NULL if the allocation fails.
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s1_trimmed;
	size_t	trimmed_len;
	size_t	i;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	trimmed_len = ft_trimmed_len(s1, set);
	s1_trimmed = (char *) malloc((trimmed_len + 1) * sizeof(char));
	if (s1_trimmed == NULL)
		return (NULL);
	if (trimmed_len == 0)
		*s1_trimmed = '\0';
	else
	{
		while (ft_isinset(s1[i], set) == TRUE)
			i++;
		ft_strlcpy(s1_trimmed, &(s1[i]), (trimmed_len + 1));
	}
	return (s1_trimmed);
}

/*
PARAMETERS
c:		The character to check.
set:	The set of charcaters to compare with c.

DESCRIPTION
This function checks if the character c is present among all the characters
in the string set.

RETURN VALUE
TRUE = 1 if c is in the set, FALSE = 0 if it is not.
*/
static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}

/*
PARAMETERS
s1:		The string to be trimmed.
set:	The set of charcaters to be trimed.

DESCRIPTION
This function calculates the length of s1 after the trim of all the characters
from the beginning and the end of the string.

RETURN VALUE
The length of the trimmed string.
*/
static size_t	ft_trimmed_len(const char *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	if (len == 0)
		return (0);
	while (ft_isinset(s1[len - 1], set) == TRUE)
	{
		if (len - 1 == 0)
			return (0);
		len--;
	}
	while (ft_isinset(s1[i], set) == TRUE)
		i++;
	return (len - i);
}
