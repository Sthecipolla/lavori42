/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 16:11:57 by lhima             #+#    #+#             */
/*   Updated: 2024/12/10 14:51:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	calcobase(char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		i ++;
	return (i);
}

static int	divisione(unsigned int num, char *base, int i, int len)
{
	if (num != 1 && num != 0)
		len += divisione(num / i, base, i, len);
	if (num != 0)
	{
		write(1, &base[num % i], 1);
		len ++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int	i;

	if (nbr == 0)
	{
		write (1, &base[0], 1);
		return (1);
	}
	i = calcobase (base);
	if (i == -1)
		return (0);
	if (nbr < 0)
	{
		write(1, "-", 1);
	}
	return (divisione(nbr, base, i, 0));
}
