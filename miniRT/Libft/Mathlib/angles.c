/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angles.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 12:59:29 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/04 14:54:27 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

//	Normalizes degrees to [0, 360) range
//	This ensures equivalence: 0° ≡ 360° ≡ 720° ≡ -360°, etc.
double_t	normalize_degrees(double_t degrees)
{
	degrees = fmod(degrees, 360.0);
	if (degrees < 0)
		degrees += 360.0;
	return (degrees);
}

//	Normalizes radians to [0, 2π) range
//	This ensures equivalence: 0 ≡ 2π ≡ 4π ≡ -2π, etc.
double_t	normalize_radians(double_t radians)
{
	radians = fmod(radians, 2.0 * M_PI);
	if (radians < 0)
		radians += 2.0 * M_PI;
	return (radians);
}

//	Converts degrees to radians
double_t	deg_to_rad(double_t degrees)
{
	return (degrees * M_PI / 180.0);
}

//	Converts radians to degrees
double_t	rad_to_deg(double_t radians)
{
	return (radians * 180.0 / M_PI);
}
