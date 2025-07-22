/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:40:53 by daromoli          #+#    #+#             */
/*   Updated: 2024/11/19 17:40:53 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The character to convert.

DESCRIPTION
If c is an uppercase letter, tolower() returns its lowercase equivalent, if a
lowercase representation exists in the current locale. Otherwise, it returns c.

RETURN VALUE
The value returned is that of the converted letter, or c if the conversion was
not possible.
*/
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}
