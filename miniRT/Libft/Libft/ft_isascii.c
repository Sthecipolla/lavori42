/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:05:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The integer to check.

DESCRIPTION
This function check if c is an ascii character.

RETURN VALUE
TRUE = 1 if c is an ascii character, FALSE = 0 otherwise.
*/
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	else
		return (FALSE);
}
