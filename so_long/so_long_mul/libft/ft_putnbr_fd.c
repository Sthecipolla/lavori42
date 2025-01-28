/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:37:27 by lhima             #+#    #+#             */
/*   Updated: 2024/11/29 16:22:33 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <fcntl.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	prin;

	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	else
		if (n < 0)
			write (fd, "-", 1);
	if (n < 0)
		prin = ((n % 10) * -1) + '0';
	else
		prin = (n % 10) + '0';
	write (fd, &prin, 1);
}
