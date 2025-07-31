/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:48:47 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:48:49 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int value, size_t num)
{
	unsigned const char	*dest;
	unsigned char		val;
	size_t				i;

	dest = (unsigned const char *) str;
	val = (unsigned char) value;
	i = 0;
	while (i < num)
	{
		if (dest[i] == val)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}
