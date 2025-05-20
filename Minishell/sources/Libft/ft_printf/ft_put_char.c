/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:41:10 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/16 19:27:58 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
PARAMETERS
fd:		The file descriptor to write to.
c:		The character to print.

DESCRIPTION
This function prints the character c on the standard output.

RETURN VALUE
This function returns the number of characters printed.
It returns -1 if the print failed.
*/
int	ft_put_char(int fd, char c)
{
	int		count;

	count = write(fd, &c, 1);
	return (count);
}
