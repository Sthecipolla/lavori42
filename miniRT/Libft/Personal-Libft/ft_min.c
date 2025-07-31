/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:42:20 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/01 11:33:55 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"

/*
PARAMETERS
a:	the first number to compare.
b:	the second number to compare.

DESCRIPTION
This function compares the numbers a and b and returns the minimum between the
two.

RETURN VALUE
The min value between a and b.
*/
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
