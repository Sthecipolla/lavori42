/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 10:00:39 by lhima             #+#    #+#             */
/*   Updated: 2024/11/29 16:24:38 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	white_space(const char *arr)
{
	int	i;

	i = 0;
	while (((arr[i] > 8) && (arr[i] < 14)) || (arr[i] == 32))
		i ++;
	return (i);
}

static int	negativo(const char *nptr, int i, int valore)
{
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		valore = valore * 10 - (nptr[i] - '0');
		i++;
	}
	return (valore);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		valore;
	char	segn;

	i = white_space(nptr);
	valore = 0;
	if (nptr[i] == '+' || nptr[i] == '-' )
		segn = nptr[i++];
	else if (nptr[i] > 47 && nptr[i] < 58)
		segn = '+';
	if ((nptr[i] > 47 && nptr[i] < 58) && (segn == '+'))
	{
		while ((nptr[i] > 47) && (nptr[i] < 58))
			valore = valore * 10 + (nptr[i++] - '0');
	}
	else if ((nptr[i] > 47 && nptr[i] < 58) && (segn == '-'))
		valore = negativo(nptr, i, valore);
	return (valore);
}
