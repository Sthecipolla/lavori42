/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_operations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 11:26:54 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/01 14:52:55 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
v:	3D vector

DESCRIPTION
This function calculates the unit vector of v (the vector which has the same
direction of v but a length of 1).

RETURN VALUE
The unit vector of v.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Unit_vector
*/
t_vector3	v3_unit_vector(t_vector3 v)
{
	return (v3_scalar_div(v, v3_module(v)));
}

/*
PARAMETERS
v1:	first vector
v2:	second vector

DESCRIPTION
This function calculates the dot product of the vectors v1 and v2.

RETURN VALUE
The dot product of v1 and v2.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Dot_product
*/
double_t	v3_dot_prod(t_vector3 v1, t_vector3 v2)
{
	return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

/*
PARAMETERS
v1:	first vector
v2:	second vector

DESCRIPTION
This function calculates the cross product of the vectors v1 and v2.

RETURN VALUE
The cross product of v1 and v2.

EXPLANATION
See https://en.wikipedia.org/wiki/Euclidean_vector#Cross_product
*/
t_vector3	v3_cross_prod(t_vector3 v1, t_vector3 v2)
{
	t_vector3	prod;

	prod.x = (v1.y * v2.z) - (v1.z * v2.y);
	prod.y = (v1.z * v2.x) - (v1.x * v2.z);
	prod.z = (v1.x * v2.y) - (v1.y * v2.x);
	return (prod);
}

/*
PARAMETERS
v1:	first vector
v2:	second vector
v3:	third vector

DESCRIPTION
This function calculates the scalar triple product of the vectors v1, v2, v3.

RETURN VALUE
The scalar triple product v1 • (v2 ⨯ v3).

EXPLANATION
See https://en.wikipedia.org/wiki/Triple_product#Scalar_triple_product
*/
double_t	v3_scalar_triple_prod(t_vector3 v1, t_vector3 v2, t_vector3 v3)
{
	return (v3_dot_prod(v1, v3_cross_prod(v2, v3)));
}

/*
PARAMETERS
v1:	first vector
v2:	second vector
v3:	third vector

DESCRIPTION
This function calculates the vector triple product of the vectors v1, v2, v3.

RETURN VALUE
The vector triple product v1 ⨯ (v2 ⨯ v3).

EXPLANATION
See https://en.wikipedia.org/wiki/Triple_product#Vector_triple_product
*/
t_vector3	v3_vector_triple_prod(t_vector3 v1, t_vector3 v2, t_vector3 v3)
{
	return (v3_cross_prod(v1, v3_cross_prod(v2, v3)));
}
