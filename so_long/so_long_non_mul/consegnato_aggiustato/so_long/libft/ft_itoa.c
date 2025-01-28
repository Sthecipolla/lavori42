/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 09:47:26 by lhima             #+#    #+#             */
/*   Updated: 2025/01/23 10:23:13 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

static	int	conv(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

static char	*zero(void)
{
	char	*mal;

	mal = (char *) malloc(2);
	if (mal == NULL)
		return (NULL);
	mal[0] = '0';
	mal[1] = '\0';
	return (mal);
}

char	*ft_itoa(int n)
{
	char	arr[100];
	int		i;
	char	*mal;
	int		x;

	i = 0;
	x = 0;
	if (n == 0)
		return (zero());
	while (n != 0)
	{
		arr[i++] = conv((n % 10)) + '0';
		if (n < 0 && n > -10)
			arr[i++] = '-';
		n = n / 10;
	}
	mal = (char *) malloc(i * sizeof(char) + 1);
	if (mal == NULL)
		return (NULL);
	while (i != 0)
		mal[x++] = arr[--i];
	mal[x] = '\0';
	return (mal);
}
