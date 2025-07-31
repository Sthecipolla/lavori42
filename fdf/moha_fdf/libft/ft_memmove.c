/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:49:03 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:49:05 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = (unsigned char *) src;
	d = (unsigned char *) dest;
	if (!dest && !src)
		return (NULL);
	else if (!n)
		return (dest);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else if (s <= d)
	{
		while (n--)
		{
			d[n] = s[n];
		}
	}
	return (dest);
}
