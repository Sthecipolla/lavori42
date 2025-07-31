/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:46:27 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/16 19:28:09 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
PARAMETERS
fd:		The file descriptor to write to.
s:		The string to print.

DESCRIPTION
This function prints the string s on the standard output.
If s is NULL, it prints (null) on the standard output.

RETURN VALUE
This function returns the number of characters printed.
It returns -1 if the print failed.
*/
int	ft_put_string(int fd, char *s)
{
	int		count;

	if (s == NULL)
		count = write(fd, "(null)", 6);
	else
		count = write(fd, s, ft_strlen(s));
	return (count);
}
