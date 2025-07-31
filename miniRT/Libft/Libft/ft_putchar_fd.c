/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 09:41:49 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/15 12:46:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "original_libft.h"

/*
PARAMETERS
c:	The character to output.
fd:	The file descriptor on which to write.

EXTERNAL FUNCTIONS
write

DESCRIPTION 
Outputs the character ’c’ to the given file descriptor.

RETURN VALUE
None.
*/
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
