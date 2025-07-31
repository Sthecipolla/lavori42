/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:09:33 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The integer to check.

DESCRIPTION
This function check if c is any printable character including space.

RETURN VALUE
TRUE = 1 if c is a printable character, FALSE = 0 otherwise.
*/
int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	else
		return (FALSE);
}
