/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:18:43 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/14 11:51:47 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
real:	real part of the complex number
imag:	imaginary part of the complex number

DESCRIPTION
This function a complex number with the real part and imaginary part specified.

RETURN VALUE
The complex number z.
*/
t_complex	ft_c_init(double_t real, double_t imag)
{
	t_complex	z;

	z.real = real;
	z.imag = imag;
	return (z);
}

/*
PARAMETERS
z:	complex number

DESCRIPTION
This function calculates the complex conjugate of the number z.

RETURN VALUE
The complex conjugate of z.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number
*/
t_complex	ft_c_conj(t_complex z)
{
	z.imag = -z.imag;
	return (z);
}

/*
PARAMETERS
z:	complex number

DESCRIPTION
This function calculates the module squared of the number z.

RETURN VALUE
The module squared of z.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number
*/
double_t	ft_c_module2(t_complex z)
{
	return ((z.real * z.real) + (z.imag * z.imag));
}

/*
PARAMETERS
z:	complex number

DESCRIPTION
This function calculates the module of the number z.

RETURN VALUE
The module of z.

EXPLANATION
See https://en.wikipedia.org/wiki/Complex_number
*/
double_t	ft_c_module(t_complex z)
{
	return (sqrt(ft_c_module2(z)));
}

/*
PARAMETERS
z:	complex number

DESCRIPTION
This function calculates the arguments of the number z.

RETURN VALUE
The arguments of z.

EXPLANATION
See https://en.wikipedia.org/wiki/Argument_(complex_analysis)
The last else corresponds to the case (z.real == 0 && z.imag == 0)
*/
double_t	ft_c_argument(t_complex z)
{
	if (z.real == 0 && z.imag > 0)
		return ((double_t) M_PI / (double_t) 2);
	else if (z.real == 0 && z.imag < 0)
		return ((double_t)(-1) * (double_t) M_PI / (double_t) 2);
	else if (z.real > 0)
		return ((double_t) atan(z.imag / z.real));
	else if (z.real < 0 && z.imag >= 0)
		return ((double_t) atan(z.imag / z.real) + (double_t) M_PI);
	else if (z.real < 0 && z.imag < 0)
		return ((double_t) atan(z.imag / z.real) - (double_t) M_PI);
	else if (z.real == 0 && z.imag == 0)
		return (NAN);
	return (NAN);
}
