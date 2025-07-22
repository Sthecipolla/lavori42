/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_operations3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:32 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/08 14:04:04 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mathlib.h"

/*
*/
t_complex	ft_c_pow(t_complex z, int exp)
{
	t_complex	result;

	result = (t_complex){1.0, 0.0};
	if (exp == 0)
		return (result);
	if (exp < 0)
	{
		z = ft_c_reciprocal(z);
		if (exp == INT_MIN)
		{
			z = ft_c_multiplication(z, z);
			exp++;
		}
		exp = -exp;
	}
	while (exp > 0)
	{
		if (exp % 2 == 1)
			result = ft_c_multiplication(result, z);
		z = ft_c_multiplication(z, z);
		exp /= 2;
	}
	return (result);
}
