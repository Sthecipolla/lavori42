/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbre_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:01:04 by lhima             #+#    #+#             */
/*   Updated: 2024/12/10 12:15:22 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

int	ft_putnbre_fd(int n, int fd, int len)
{
	char	prin;

	if (n >= 10 || n <= -10)
		len = ft_putnbre_fd(n / 10, fd, ++len);
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			len ++;
		}
	}
	if (n < 0)
		prin = ((n % 10) * -1) + '0';
	else
		prin = (n % 10) + '0';
	write (fd, &prin, 1);
	return (len);
}
