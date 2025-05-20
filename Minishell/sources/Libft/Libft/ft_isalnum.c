/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 08:57:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The integer to check.

DESCRIPTION
This function check if c is an alphanumeric character; it is equivalent to
	(ft_isalpha(c) || ft_isdigit(c))

RETURN VALUE
TRUE = 1 if c is an alphanumeric character, FALSE = 0 otherwise.
*/
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == TRUE || ft_isdigit(c) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}
