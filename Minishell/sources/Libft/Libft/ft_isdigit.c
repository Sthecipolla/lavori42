/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:48:25 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The integer to check.

DESCRIPTION
This function check if c is a digit (0 through 9).

RETURN VALUE
TRUE = 1 if c is a digit, FALSE = 0 otherwise.
*/
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (TRUE);
	else
		return (FALSE);
}
