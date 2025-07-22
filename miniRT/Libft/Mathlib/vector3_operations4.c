/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_operations4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:34:29 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/15 16:27:09 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
v:		3D vector that needs to be rotated
axis:	axis aroud which the rotation happens
theta:	angle (in radians) of the rotation

DESCRIPTION
This function calculates the rotation of angle theta of the vector v around
the vector axis.

RETURN VALUE
The rotated vector.

EXPLANATION
See https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula
*/
t_vector3	v3_rotate_around_axis(t_vector3 v, t_vector3 axis, double_t theta)
{
	t_vector3	result;
	t_vector3	term1;
	t_vector3	term2;
	t_vector3	term3;
	double_t	cos_theta;

	axis = v3_unit_vector(axis);
	cos_theta = cos(theta);
	term1 = v3_scalar_prod(cos_theta, v);
	term2 = v3_scalar_prod(sin(theta), v3_cross_prod(axis, v));
	term3 = v3_scalar_prod(v3_dot_prod(axis, v) * (1 - cos_theta), axis);
	result = v3_sum(term1, v3_sum(term2, term3));
	return (result);
}
