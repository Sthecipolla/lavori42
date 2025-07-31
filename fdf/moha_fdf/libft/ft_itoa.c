/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:48:12 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 16:48:14 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putninstr(int n, int len, char *str)
{
	if (n < 0)
	{
		n = -n;
	}
	if (n >= 0)
	{
		while (n >= 0 && len >= 0)
		{
			str[len] = n % 10 + 48;
			n = n / 10;
			len --;
		}
	}
}

static int	ft_superlen(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		i = 1;
		if (n == 0)
			return (i);
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = ft_superlen(n);
	str = ft_calloc(sizeof(char), (len + 1));
	if (str == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strlcpy(str, "-2147483648", 12);
		return (str);
	}
	ft_putninstr(n, len - 1, str);
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*int main (void)
{
	char *str = ft_itoa(-2147483648);
	printf("I%s\n", str);
	//free (str);
}*/
