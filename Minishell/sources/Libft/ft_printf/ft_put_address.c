/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_address.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 10:24:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/16 19:27:53 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
PARAMETERS
fd:		The file descriptor to write to.
mem:	The memory address to print.

DESCRIPTION
This function prints the memory address pointed to by mem.

RETURN VALUE
This function returns the number of characters printed (count) or ERROR = -1 if
an error occurs.

EXPLANATION
If the pointer mem is NULL, this function writes (nil).
Otherwise, the memory address is cast to size_t (unsigned long): a void pointer
is an 8 bytes memory address, so it can be represented in an 8 bytes unsigned
number size_t. Then this number is printed using ft_putsize_t_base_count.
If an error occurs at any moment, so tmp_count = ERROR = -1, then ERROR = -1
is returned and the execution stops.
*/
int	ft_put_address(int fd, void *mem)
{
	int		count;
	int		tmp_count;
	size_t	mem_ul;

	count = 0;
	if (mem == 0)
	{
		tmp_count = write(fd, "(nil)", 5);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
	}
	else
	{
		mem_ul = (size_t) mem;
		tmp_count = write(fd, "0x", 2);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
		tmp_count = ft_put_unsigned_long_base(fd, mem_ul, HEX_LOWERCASE_BASE);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
	}
	return (count);
}
