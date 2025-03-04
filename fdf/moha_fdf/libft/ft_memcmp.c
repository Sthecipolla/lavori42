/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:48:54 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:48:56 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *dest, const void *src, size_t len)
{
	unsigned char		*dest1;
	unsigned char		*src1;
	unsigned int		i;

	if (len == 0)
		return (0);
	src1 = (unsigned char *)src;
	dest1 = (unsigned char *)dest;
	i = 0;
	while (src1[i] == dest1[i] && i < len - 1)
		i++;
	if (i != len)
		return (dest1[i] - src1[i]);
	return (0);
}
