/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:58:09 by lhima             #+#    #+#             */
/*   Updated: 2024/11/29 14:16:09 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dest2;
	char	*src2;
	int		y;

	y = 0;
	dest2 = (char *) dest;
	src2 = (char *) src;
	if (dest2 < src2)
	{
		while (y < (int) n)
		{
			dest2[y] = src2[y];
			y ++;
		}
	}
	else if (dest2 > src2)
	{
		y = n;
		while (--y >= 0)
			dest2[y] = src2[y];
	}
	return (dest);
}
