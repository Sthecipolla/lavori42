/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 08:30:19 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETER
s: The string from which to create the substring.
start: The start index of the substring in the string ’s’.
len: The maximum length of the substring.

EXTERNAL FUNCTIONS
malloc

DESCRIPTION
Allocates (with malloc(3)) and returns a substring from the string ’s’.
The substring begins at index ’start’ and is of maximum size ’len’.

RETURN VALUE
The substring. NULL if the allocation fails.

EXPLANATION
The function starts by calculating the length of s (s_len).
If s_len is less than start, the substring (sub_s) should be extracted from
outside of the original string, so only a byte is reserved for sub_s, it is
filled with the null-terminating character and then returned.
If s_len is equal or greater than start, then malloc reserves for sub_s a #
of bytes equal to the minimum beetween len and s_len - start, plus 1 byte
for the null-terminating character. Then, starting from start, the elements
of s are copied into sub_s until len elements are copied or s ends.
Why only the minimum beetween len and s_len - start bytes are needed for the
substring? For example, if s = "Bonjour!" then s_len = 8.
If len = 5 and start = 6, only the last two characters of the string should
be included in the substring, so I need to allocate only
	(s_len - start) + 1 = (8 - 6) + 1 = 2 + 1
bytes for sub_s and sub_s will be "r!".
Instead, if len = 5 and start = 1, then I can copy the full 5 bytes before s
ends, so I need to allocate
	len + 1 = 5 + 1
bytes for sub_s and su_s will be "onjou".
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_s;
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	if (s_len < (size_t) start)
		sub_s = (char *) malloc(sizeof(char));
	else if (len <= s_len - (size_t) start)
		sub_s = (char *) malloc((len + 1) * sizeof(char));
	else
		sub_s = (char *) malloc((s_len - (size_t) start + 1) * sizeof(char));
	if (sub_s == NULL)
		return (NULL);
	i = 0;
	if (!(s_len < (size_t) start))
	{
		while (i < len && s[start + i] != '\0')
		{
			sub_s[i] = s[start + i];
			i++;
		}
	}
	sub_s[i] = '\0';
	return (sub_s);
}
