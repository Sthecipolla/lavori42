/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_int_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:47:01 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/16 19:28:17 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_base_calc_length(char *base);
static int	calc_print_figure(int fd, unsigned int nbr, int length, char *base);

/*
PARAMETERS
fd:		The file descriptor to write to.
nbr:	The decimal positive (unsigned) integer to print.
base:	The base to convert and print nbr into.

DESCRIPTION
This function prints the decimal unsigned number nbr in a base system in the
file describted by fd, while it counts the number of characters printed.

RETURN VALUE
The number of printed characters or ERROR = -1 if an error occurs.

EXPLANATION
It uses the function check_base_calc_length to check whether the base is ok or
not, and to calculate its length (which base it is). Then, if the base is ok,
it prints the number in that base using the function calc_print_figure.
If an error occurs at any moment, so tmp_count = ERROR = -1, then ERROR = -1
is returned and the execution stops.
*/
int	ft_put_unsigned_int_base(int fd, unsigned int nbr, char *base)
{
	int		length;
	int		count;
	int		tmp_count;

	count = 0;
	length = check_base_calc_length(base);
	if (length != 0)
	{
		tmp_count = calc_print_figure(fd, nbr, length, base);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
	}
	return (count);
}

/*
PARAMETERS
base:	The base to check.

DESCRIPTION
This function checks if base is a correct base system and calculates which
base system is (its length).

RETURN VALUE
If the base is not correct it returns 0, otherwise it returns the length of
the base. The base is incorrect if it is empty or size of 1, if it contains
the same character twice or if it contains '+' or '-'.
*/
static int	check_base_calc_length(char *base)
{
	int		length;
	int		j;

	length = 0;
	while (base[length] != '\0')
	{
		if (base[length] == '+' || base[length] == '-')
			return (0);
		j = length + 1;
		while (base[j] != '\0')
		{
			if (base[length] == base[j])
				return (0);
			j++;
		}
		length++;
	}
	if (length <= 1)
		return (0);
	return (length);
}

/*
PARAMETERS
fd:		The file descriptor to write to.
nbr:	The decimal integer to convert and print.
length:	The length of the base to print to.
base:	The base to convert and print to.

DESCRIPTION
This is a recursive function which converts "number" from the decimal base
to the base system "base" and prints it, while it counts the number of char
which are printed (variable count).

RETURN VALUE
The number of printed characters or ERROR = -1 if an error occurs.

EXPLANATION
This function divides the number by the length of the base ("length") and
recalls itself until the result of the division is 0. Then it prints the
letter in base correspondent to the remainder of the division for each
recursion. Every write increments the variable count by the amount of
characters printed. count is then returned to be used by the precedent call
of this recursive function, or by the ft_putnbr_base_count function.
If an error occurs at any moment, so tmp_count = ERROR = -1, then ERROR = -1
is returned and the execution stops.
*/
static int	calc_print_figure(int fd, unsigned int nbr, int length, char *base)
{
	int		count;
	int		tmp_count;

	count = 0;
	if (nbr / length != 0)
	{
		tmp_count = calc_print_figure(fd, nbr / length, length, base);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
	}
	tmp_count = write(fd, &base[nbr % length], 1);
	if (tmp_count == ERROR)
		return (ERROR);
	count += tmp_count;
	return (count);
}
