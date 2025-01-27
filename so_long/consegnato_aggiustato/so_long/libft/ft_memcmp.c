/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:21:09 by lhima             #+#    #+#             */
/*   Updated: 2025/01/23 10:21:28 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	ft_memcmp(const void *b1, const void *b2, size_t len)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char *) b1;
	s2 = (unsigned char *) b2;
	i = 0;
	if (len == 0)
		return (0);
	while ((s1[i] == s2[i]) && (i < len - 1))
		i ++;
	return ((int ) s1[i] - s2[i]);
}
