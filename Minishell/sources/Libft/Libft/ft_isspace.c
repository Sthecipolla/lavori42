/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:54:19 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	the character that I want to check if it is a whitespace.

DESCRIPTION
This function is an implementation of the isspace(3) function. It is used by
ft_atoi to know if a character is a whitespace character or not. Whitespace
characters in C are: space (32), \t (9), \n (10), \v (11), \f (12), \r (13).

RETURN VALUE
TRUE = 1 if c is a whitespace, FALSE = 0 if c is not a whitespace.
*/
int	ft_isspace(int c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (TRUE);
	else
		return (FALSE);
}
