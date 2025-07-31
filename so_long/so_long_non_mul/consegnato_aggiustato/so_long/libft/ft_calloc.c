/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:40:15 by lhima             #+#    #+#             */
/*   Updated: 2024/12/03 14:21:27 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*s;
	size_t		i;

	i = 0;
	s = malloc(nmemb * size);
	if (s == NULL)
		return (NULL);
	while (i < nmemb * size)
	{
		((unsigned char *)s)[i ++] = '\0';
	}
	return ((void *)s);
}
