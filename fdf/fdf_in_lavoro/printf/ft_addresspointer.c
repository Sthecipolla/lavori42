/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addresspointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:10:16 by lhima             #+#    #+#             */
/*   Updated: 2024/12/10 15:40:47 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>
#include <stdint.h>

static int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

static	int	ft_exa(unsigned long nbr)
{
	char	*s;
	int		i;

	i = 0;
	s = "0123456789abcdef";
	if (nbr >= 16)
		i += ft_exa(nbr / 16);
	i += ft_putchar_fd(s[nbr % 16]);
	return (i);
}

int	ft_addpo(unsigned long nbr)
{
	int	i;

	i = 2;
	if (!nbr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	write(1, "0x", 2);
	i += ft_exa(nbr);
	return (i);
}
