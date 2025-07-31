/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 13:37:57 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/08 14:03:40 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
z1:	first complex number
z2:	second complex number

DESCRIPTION
This function calculates the sum of the numbers z1 and z2.

RETURN VALUE
The sum of z1 and z2.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number#Addition_and_subtraction
*/
t_complex	ft_c_sum(t_complex z1, t_complex z2)
{
	t_complex	sum;

	sum.real = z1.real + z2.real;
	sum.imag = z1.imag + z2.imag;
	return (sum);
}

/*
PARAMETERS
z1:	first complex number
z2:	second complex number

DESCRIPTION
This function calculates the difference of the numbers z1 and z2.

RETURN VALUE
The difference of z1 and z2.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number#Addition_and_subtraction
*/
t_complex	ft_c_difference(t_complex z1, t_complex z2)
{
	t_complex	diff;

	diff.real = z1.real - z2.real;
	diff.imag = z1.imag - z2.imag;
	return (diff);
}

/*
PARAMETERS
z1:	first complex number
z2:	second complex number

DESCRIPTION
This function calculates the multiplication of the numbers z1 and z2.

RETURN VALUE
The multiplication of z1 and z2.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number#Multiplication
*/
t_complex	ft_c_multiplication(t_complex z1, t_complex z2)
{
	t_complex	mult;

	mult.real = (z1.real * z2.real) - (z1.imag * z2.imag);
	mult.imag = (z1.real * z2.imag) + (z1.imag * z2.real);
	return (mult);
}

/*
PARAMETERS
z:	complex number

DESCRIPTION
This function calculates the reciprocal of the number z.

RETURN VALUE
The reciprocal of the number z.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number
*/
t_complex	ft_c_reciprocal(t_complex z)
{
	t_complex	reciprocal;
	double_t	module2;

	module2 = ft_c_module2(z);
	reciprocal.real = z.real / module2;
	reciprocal.imag = (double_t)(-1) * z.imag / module2;
	return (reciprocal);
}

/*
PARAMETERS
z1:	first complex number
z2:	second complex number

DESCRIPTION
This function calculates the division between the numbers z1 and z2.

RETURN VALUE
The division between the numbers z1 and z2.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number
*/
t_complex	ft_c_division(t_complex z1, t_complex z2)
{
	t_complex	quotient;
	double_t	module2_z2;

	module2_z2 = ft_c_module2(z2);
	quotient.real = ((z1.real * z2.real) + (z1.imag * z2.imag)) / module2_z2;
	quotient.imag = ((z1.imag * z2.real) - (z1.real * z2.imag)) / module2_z2;
	return (quotient);
}
