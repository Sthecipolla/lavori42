/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:23:52 by lhima             #+#    #+#             */
/*   Updated: 2024/11/30 12:12:57 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*arr;
	unsigned char	a;
	size_t			t;

	arr = (unsigned char *)b;
	a = (unsigned char)c;
	t = 0;
	while (t < n)
	{
		if (arr[t] == a)
			return ((void *)&arr[t]);
		t++;
	}
	return (NULL);
}
