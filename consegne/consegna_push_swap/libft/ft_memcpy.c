/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:12:18 by lhima             #+#    #+#             */
/*   Updated: 2024/12/02 11:29:17 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*arr;
	char	*srr;
	size_t	y;

	y = 0;
	if (!src && !dest)
		return (NULL);
	srr = (char *) src;
	arr = (char *) dest;
	while ((y < n))
	{
		arr[y] = srr[y];
		y ++;
	}
	return ((void *)arr);
}
