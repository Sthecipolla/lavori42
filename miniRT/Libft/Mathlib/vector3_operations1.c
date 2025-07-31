/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_operations1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 10:54:46 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/01 14:52:53 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
x:	x component of the vector
y:	y component of the vector
z:	z component of the vector

DESCRIPTION
This function initialize a vector with the components specified.

RETURN VALUE
The vector v.
*/
t_vector3	v3_init(double_t x, double_t y, double_t z)
{
	t_vector3	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

/*
PARAMETERS
v:	3D vector

DESCRIPTION
This function calculates the module squared of the vector v.

RETURN VALUE
The module squared of v.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Length
*/
double_t	v3_module2(t_vector3 v)
{
	return ((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/*
PARAMETERS
v:	3D vector

DESCRIPTION
This function calculates the module of the vector v.

RETURN VALUE
The module of v.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Length
*/
double_t	v3_module(t_vector3 v)
{
	return (sqrt(v3_module2(v)));
}

/*
PARAMETERS
v1:	first vector
v2:	second vector

DESCRIPTION
This function calculates the sum of the vectors v1 and v2.

RETURN VALUE
The sum of v1 and v2.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Addition_and_subtraction
*/
t_vector3	v3_sum(t_vector3 v1, t_vector3 v2)
{
	t_vector3	sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;
	sum.z = v1.z + v2.z;
	return (sum);
}

/*
PARAMETERS
v1:	first vector
v2:	second vector

DESCRIPTION
This function calculates the difference between the vectors v1 and v2.

RETURN VALUE
The difference between v1 and v2 (v1 - v2).

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Addition_and_subtraction
*/
t_vector3	v3_diff(t_vector3 v1, t_vector3 v2)
{
	t_vector3	diff;

	diff.x = v1.x - v2.x;
	diff.y = v1.y - v2.y;
	diff.z = v1.z - v2.z;
	return (diff);
}
