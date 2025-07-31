/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:24:39 by lhima             #+#    #+#             */
/*   Updated: 2024/11/29 16:09:00 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*arr;
	size_t			y;

	y = 0;
	arr = (unsigned char *) s;
	while (y < n)
	{
		arr[y] = c;
		y ++;
	}
	return (s);
}
