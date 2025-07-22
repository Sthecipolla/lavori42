/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 11:39:12 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/01 11:33:59 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"

/*
PARAMETERS
a:	the first number to compare.
b:	the second number to compare.

DESCRIPTION
This function compares the numbers a and b and returns the maximum between the
two.

RETURN VALUE
The max value between a and b.
*/
int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}
