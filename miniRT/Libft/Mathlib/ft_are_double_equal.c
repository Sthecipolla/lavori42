/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_double_equal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:13:56 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/04 14:17:52 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
PARAMETERS
n1 & n2:	the two numbers to compare
epsilon:	tolerance

DESCRIPTION
This function checks if the two double numbers are equal, with a tolerance of
epsilon (if they differ by a numeber smaller than epsilon, they are condidered
equal and not different).

RETURN VALUE
TRUE if n1 and n2 are equal within the tolerance, FALSE otherwise.
*/
bool	ft_are_double_equal(double_t n1, double_t n2, double_t epsilon)
{
	double_t	diff;

	if (epsilon < 0)
		epsilon = fabs(epsilon);
	diff = fabs(n1 - n2);
	if (diff < epsilon)
		return (TRUE);
	else
		return (FALSE);
}
