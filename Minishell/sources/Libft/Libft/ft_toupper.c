/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:38:52 by daromoli          #+#    #+#             */
/*   Updated: 2024/11/19 17:38:52 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The character to convert.

DESCRIPTION
If c is a lowercase letter, toupper() returns its upperecase equivalent, if an
uppercase representation exists in the current locale. Otherwise, it returns c.

RETURN VALUE
The value returned is that of the converted letter, or c if the conversion was
not possible.
*/
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}
