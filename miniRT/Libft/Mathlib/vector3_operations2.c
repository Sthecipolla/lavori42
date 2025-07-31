/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:05:07 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/01 14:53:51 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
p1:	first point in space
p2: second point in space

DESCRIPTION
This function calculates the distance squared between the points p1 and p2.

RETURN VALUE
The distance squared between p1 and p2.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_distance#Higher_dimensions
*/
double_t	v3_dist2(t_point3 p1, t_point3 p2)
{
	return (v3_module2(v3_diff(p1, p2)));
}

/*
PARAMETERS
p1:	first point in space
p2: second point in space

DESCRIPTION
This function calculates the distance between the points p1 and p2.

RETURN VALUE
The distance between p1 and p2.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_distance#Higher_dimensions
*/
double_t	v3_dist(t_point3 p1, t_point3 p2)
{
	return (v3_module(v3_diff(p1, p2)));
}

/*
PARAMETERS
v:	3D vector

DESCRIPTION
This function calculates the opposite of the vector v.

RETURN VALUE
The opposite of v.

EXPLANATION
See https://chk.me/dPVOBP3
*/
t_vector3	v3_opposite(t_vector3 v)
{
	t_vector3	opposite;

	opposite.x = (-v.x);
	opposite.y = (-v.y);
	opposite.z = (-v.z);
	return (opposite);
}

/*
PARAMETERS
k:	scalar number
v:	3D vector

DESCRIPTION
This function calculates the product between the scalar k and the vector v.

RETURN VALUE
The product between k and v.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Scalar_multiplication
*/
t_vector3	v3_scalar_prod(double_t k, t_vector3 v)
{
	t_vector3	prod;

	prod.x = v.x * k;
	prod.y = v.y * k;
	prod.z = v.z * k;
	return (prod);
}

/*
PARAMETERS
v:	3D vector
t:	scalar number

DESCRIPTION
This function calculates the division between the vector v and the scalar t.

RETURN VALUE
The division between v and t.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Scalar_multiplication
*/
t_vector3	v3_scalar_div(t_vector3 v, double_t t)
{
	t_vector3	div;

	div.x = v.x / t;
	div.y = v.y / t;
	div.z = v.z / t;
	return (div);
}
