/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 13:42:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/07 15:22:14 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"
#include <limits.h>

static size_t	ft_str_length(long n);
static void		ft_n_to_str(char *str, long n, size_t length);

/*
PARAMETERS
n:	The integer to convert.

EXTERNAL FUNCTIONS
malloc

DESCRIPTION
Allocates (with malloc(3)) and returns a string representing the integer
received as an argument. Negative numbers must be handled.

RETURN VALUE
The string representing the integer. NULL if the allocation fails.
*/
char	*ft_ltoa(long n)
{
	char	*str;
	size_t	length;

	length = ft_str_length(n);
	str = (char *) malloc((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_n_to_str(str, n, length);
	return (str);
}

/*
PARAMETERS
n:	the integer whose length is to be calculated.

DESCRIPTION
This function calculates the length of the stgring needed to store the number n.

RETURN VALUE
The length of the string needed to store the number n.

EXPLANATION
If n is negative, length is incremented to store the '-' sign. If n = 0, length
is incremented to 1 and returned. Then, every division by 10 counts one digit of
the number, so when n reaches 0 lenght is equal to the number of digits plus
eventually 1 if the sign is -.
*/
static size_t	ft_str_length(long n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

/*
PARAMETERS
str:	the string to write the number n in.
n:		the integer to write inside str.
length:	the length of the string str.

DESCRIPTION
This function writes the number n to the array str.

RETURN VALUE
None.

EXPLANATION
length is the length of str, and it is big enough to contain the number n, its
sign if it is '-', and the null-terminating character '\0'.
This function works for all integers. It starts by nul-terminating str.
If n = 0, it writes 0 in str. If n = LONG_MIN it writes the 8 at the end of
the string and continues the execution with n / 10, to avoid integer overflow.
If n < 0, it writes '-' in str and it flips the sign of n. Then, it calculates
every digit of n in str starting from the end of the number: it takes n % 10
(which is the unit digit of n), tranforms it into character by adding '0', and
goes to the next digit by dividing n by 10.
*/
static void	ft_n_to_str(char *str, long n, size_t length)
{
	str[length] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n == LONG_MIN)
	{
		length--;
		str[length] = '8';
		n = n / 10;
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		length--;
		str[length] = '0' + (n % 10);
		n = n / 10;
	}
}
