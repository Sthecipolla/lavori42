/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:11:20 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/01 11:34:03 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"

static int		sign_of_array(char **str);
static double	ft_calc_integer(char **str);
static double	ft_calc_fraction(char **str);

/*
*/
double	ft_atof(const char *nptr)
{
	double	number;
	double	sign;
	double	frac;
	char	*str;

	str = (char *) nptr;
	while (ft_isspace(*str) == TRUE)
		str++;
	sign = (double) sign_of_array(&str);
	number = ft_calc_integer(&str);
	if (*str == '.')
	{
		str++;
		frac = ft_calc_fraction(&str);
	}
	else
		frac = 0.0;
	number = number + frac;
	return (sign * number);
}

/*
PARAMETERS
str:		pointer to the string that contains the number.

DESCRIPTION
This function returns the sign of the number cointained in *str for ft_atof.

RETURN VALUE
+1 if the sign is positive, -1 if the sign is negative.

EXPLANATION
If a - is found, it cha + fracnges the sign.
*/
static int	sign_of_array(char **str)
{
	int		sign;

	sign = 1;
	while (**str == '+' || **str == '-')
	{
		if (**str == '-')
			sign = sign * (-1);
		(*str)++;
	}
	return (sign);
}

static double	ft_calc_integer(char **str)
{
	double	number;

	number = 0.0;
	while (ft_isdigit(**str) == TRUE)
	{
		number = number * 10.0 + (**str - '0');
		(*str)++;
	}
	return (number);
}

static double	ft_calc_fraction(char **str)
{
	double	i;
	double	frac;

	i = 0.1;
	frac = 0.0;
	while (ft_isdigit(**str) == TRUE)
	{
		frac = frac + (i * (double)(**str - '0'));
		i = i * 0.1;
		(*str)++;
	}
	return (frac);
}
