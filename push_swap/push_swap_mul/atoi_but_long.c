/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_but_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:27:44 by lhima             #+#    #+#             */
/*   Updated: 2025/02/11 16:28:11 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	white_space(const char *arr)
{
	int	i;

	i = 0;
	while (((arr[i] > 8) && (arr[i] < 14)) || (arr[i] == 32))
		i++;
	return (i);
}

static long	negativo(const char *nptr, int i, long valore)
{
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		valore = valore * 10 - (nptr[i] - '0');
		i++;
	}
	return (valore);
}

long	ft_atoi_long(const char *nptr)
{
	int		i;
	long	valore;
	char	segn;

	i = white_space(nptr);
	valore = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
		segn = nptr[i++];
	else if (nptr[i] > 47 && nptr[i] < 58)
		segn = '+';
	if ((nptr[i] > 47 && nptr[i] < 58) && (segn == '+'))
	{
		while ((nptr[i] > 47) && (nptr[i] < 58))
			valore = valore * 10 + (nptr[i++] - '0');
	}
	else if ((nptr[i] > 47 && nptr[i] < 58) && (segn == '-'))
		return (negativo(nptr, i, valore));
	return (valore);
}
