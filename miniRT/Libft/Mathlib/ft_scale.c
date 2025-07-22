/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:14:16 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/03 14:44:24 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
num:	number to rescale
old:	struct which contains min and max values of the old scale
new:	struct which contains min and max values of the new scale

DESCRIPTION
This function rescales the number num from the old scale to the new scale,
using a linear interpolation.

RETURN VALUE
The number num rescaled to the new scale.

EXPLANATION
The elements in the formulas below are:
-	old.max - old.min
		->	lenght of the old scale
-	new.max - new.min
		->	lenght of the new scale
-	num - old.min
		->	distance of num from the beginning of the old scale
-	(new.max - new.min) / (old.max - old.min) = s_factor
		->	scale factor
-	s_factor * (num - old.min)
		->	distance of the new_num from the beginning of the new scale
-	[s_factor * (num - old.min)] + new.min
		->	number expressed in the new scale
*/
double_t	ft_scale(double_t num, t_scale old, t_scale new)
{
	double_t	s_factor;
	double_t	new_num;

	s_factor = (new.max - new.min) / (old.max - old.min);
	new_num = (s_factor * (num - old.min)) + new.min;
	return (new_num);
}
