/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:20 by lhima             #+#    #+#             */
/*   Updated: 2025/03/13 13:45:20 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	white_space(const char *arr)
{
	int	i;

	i = 0;
	while (((arr[i] > 8) && (arr[i] < 14)) || (arr[i] == 32))
		i++;
	return (i);
}

static long long	negativo(const char *nptr, int i, long long valore)
{
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		valore = valore * 10 - (nptr[i] - '0');
		i++;
	}
	return (valore);
}

long long	ft_atol(const char *nptr)
{
	int			i;
	long long	valore;
	char		segn;

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
