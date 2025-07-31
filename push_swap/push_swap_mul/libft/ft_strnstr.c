/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:25:59 by lhima             #+#    #+#             */
/*   Updated: 2024/11/30 16:30:43 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *big,	const char *little, size_t len)
{
	size_t	i;
	size_t	i2;

	i = 0;
	i2 = 0;
	if (ft_strlen((char *)little) == 0)
		return ((char *)big);
	if (ft_strlen((char *)big) == 0)
		return (NULL);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + i2] == little[i2] && little[i2] != '\0')
			i2 ++;
		if (little[i2] == '\0' && i + i2 <= len)
			return ((char *)&big[i]);
		i2 = 0;
		i ++;
	}
	return (NULL);
}
