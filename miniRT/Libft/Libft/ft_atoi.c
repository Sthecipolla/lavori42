/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:34:22 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

static int	sign_of_array(char *str, char **ptr_1_el);

/*
PARAMETERS
nptr:	the string to convert to integer.

DESCRIPTION
The atoi() function converts the initial portion of the string pointed to by
nptr to int. The behavior is the same as
	strtol(nptr, NULL, 10);
except that atoi() does not detect errors.

RETURN VALUE
The converted value.

EXPLANATION
This function returns an int version of the string str taken as an argument.
sign will contain the sign of the number and number the number itself. The
function starts by ignoring all the whitespaces at the beginning of str. Then
it calculates the sign using sign_of_array. Then it uses the ptr_1_el form the
sign_of_array function to jump the sign '+' or '-' (if present). Then it goes
to the end of the number, and it goes backward to ptr_1_el in while loop where
it calculates the number in an int version. At the end the multiplication 
between the sign and the number is returned.
*/
int	ft_atoi(const char *nptr)
{
	int		number;
	int		sign;
	int		i;
	char	*ptr_1_el;
	char	*str;

	str = (char *) nptr;
	number = 0;
	i = 1;
	while (ft_isspace(*str) == TRUE)
		str++;
	sign = sign_of_array(str, &ptr_1_el);
	str = ptr_1_el;
	while (*str >= 48 && *str <= 57)
		str++;
	if (str == ptr_1_el)
		return (0);
	while (str > ptr_1_el)
	{
		str--;
		number = number + i * (int)(*str - 48);
		i = i * 10;
	}
	return (number * sign);
}

/*
PARAMETERS
nptr:	the string to convert to integer.

DESCRIPTION
The atol() function converts the initial portion of the string pointed to by
nptr to long. The atol() function does not detect errors.

RETURN VALUE
The converted value.

EXPLANATION
This function returns a long version of the string str taken as an argument.
sign will contain the sign of the number and number the number itself. The
function starts by ignoring all the whitespaces at the beginning of str. Then
it calculates the sign using sign_of_array. Then it uses the ptr_1_el form the
sign_of_array function to jump the sign '+' or '-' (if present). Then it goes
to the end of the number, and it goes backward to ptr_1_el in while loop where
it calculates the number in an int version. At the end the multiplication 
between the sign and the number is returned.
*/
long	ft_atol(const char *nptr)
{
	long	number;
	int		sign;
	long	i;
	char	*ptr_1_el;
	char	*str;

	str = (char *) nptr;
	number = 0;
	i = 1;
	while (ft_isspace(*str) == TRUE)
		str++;
	sign = sign_of_array(str, &ptr_1_el);
	str = ptr_1_el;
	while (*str >= 48 && *str <= 57)
		str++;
	if (str == ptr_1_el)
		return (0);
	while (str > ptr_1_el)
	{
		str--;
		number = number + i * (long)(*str - 48);
		i = i * 10;
	}
	return (number * (long) sign);
}

/*
PARAMETERS
nptr:	the string to convert to integer.

DESCRIPTION
The atoll() function converts the initial portion of the string pointed to by
nptr to long long. The atoll() function does not detect errors.

RETURN VALUE
The converted value.

EXPLANATION
This function returns a t_llong version of the string str taken as an argument.
sign will contain the sign of the number and number the number itself. The
function starts by ignoring all the whitespaces at the beginning of str. Then
it calculates the sign using sign_of_array. Then it uses the ptr_1_el form the
sign_of_array function to jump the sign '+' or '-' (if present). Then it goes
to the end of the number, and it goes backward to ptr_1_el in while loop where
it calculates the number in an int version. At the end the multiplication 
between the sign and the number is returned.
*/
t_llong	ft_atoll(const char *nptr)
{
	t_llong	number;
	int		sign;
	t_llong	i;
	char	*ptr_1_el;
	char	*str;

	str = (char *) nptr;
	number = 0;
	i = 1;
	while (ft_isspace(*str) == TRUE)
		str++;
	sign = sign_of_array(str, &ptr_1_el);
	str = ptr_1_el;
	while (*str >= 48 && *str <= 57)
		str++;
	if (str == ptr_1_el)
		return (0);
	while (str > ptr_1_el)
	{
		str--;
		number = number + i * (t_llong)(*str - 48);
		i = i * 10;
	}
	return (number * (t_llong) sign);
}

/*
PARAMETERS
str:		string that contains the number.
ptr_1_el:	variable which I use to return the pointer to the first element in
			str after the sign 

DESCRIPTION
This function returns the sign of the number cointained in str for ft_atoi.

RETURN VALUE
+1 if the sign is positive, -1 if the sign is negative.

EXPLANATION
If a - is found, it changes the sign.
The ptr_1_el is needed to return to the function ft_atoi a pointer to the first
character of str that is not a + or a -, so I don't need another while loop in 
the function ft_atoi to come back to that point.
*/
static int	sign_of_array(char *str, char **ptr_1_el)
{
	int		sign;

	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * (-1);
		str++;
	}
	*ptr_1_el = str;
	return (sign);
}
