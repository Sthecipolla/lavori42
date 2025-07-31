/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:29:48 by lhima             #+#    #+#             */
/*   Updated: 2025/01/08 12:35:55 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	check_type(const char c,	va_list arg)
{
	int	len;

	len = 0;
	if (c == 's')
		len = ft_putstra_fd(va_arg(arg, char *), 1);
	else if (c == 'c')
		len = ft_putchare_fd(va_arg(arg, int), 1);
	else if (c == 'd' || c == 'i')
		len = ft_putnbre_fd(va_arg(arg, int), 1, 1);
	else if (c == 'u')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789");
	else if (c == 'x')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		len = ft_putnbr_base(va_arg(arg, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		len = ft_addpo((long)va_arg(arg, void *));
	return (len);
}

int	ft_printf(const char *c, ...)
{
	va_list		args;
	int			len;

	va_start(args, c);
	len = 0;
	while (*c != '\0')
	{
		if (*c == '%')
		{
			c++;
			if (*c == '%')
				len += ft_putchare_fd('%', 1);
			else
				len += check_type(*c, args);
		}
		else
			len += ft_putchare_fd(*c, 1);
		c++;
	}
	return (len);
}

/*  int	main(void)
{
	int	a;
	int	b;

	int	c = 16;
	//TEST(4, print(" %p ", 16));
	a = ft_printf(" %u \n", c);
	b = printf(" %u \n", c);
	printf("%d\n", a);
	printf("%d\n", b);
}  */