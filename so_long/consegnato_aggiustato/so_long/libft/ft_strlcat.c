/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:58:03 by lhima             #+#    #+#             */
/*   Updated: 2024/11/29 16:57:42 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		i2;
	size_t		dst2;
	size_t		scr2;

	dst2 = ft_strlen(dst);
	scr2 = ft_strlen(src);
	i = dst2;
	i2 = 0;
	if (size <= dst2)
		return (size + scr2);
	while (i < size - 1 && src[i2] != '\0')
	{
		dst[i] = src[i2];
		i2 ++;
		i ++;
	}
	dst[i] = '\0';
	return (dst2 + scr2);
}
