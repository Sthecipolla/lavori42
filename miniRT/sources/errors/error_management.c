/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:21:26 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/10 12:17:10 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static char	*ft_strerror(int errnmb);

/*
PARAMETERS
func:	name of function or program which caused the error
s:		name of file or program to write prior the error message

DESCRIPTION
This function prints an error on the stderr in the format:
	"function/program": (optional)"file/command": "error message"
The function or program which caused the error is printed first.
Then the file or command which caused the error is optionally printed, if the
value passed to the variable s is not NULL.
At the end, the error message is printed. The error message is obtained using
the function ft_strerror based on the value contained in errno.

RETURN VALUE
It returns the error number of the error it printed.

EXPLANATION
The errors are printed using the ft_dprintf function, which is a modified
version of ft_printf which let the user choose on which fd to print.
The value of errno is saved in the ev variable, so if the write function in
ft_dprintf fails (and changes the value of errno), the errno value of the
original error is not lost and can be returned.
*/
int	ft_print_error(char *func, char *s, int ev)
{
	ft_dprintf(STDERR_FILENO, "Error\n");
	if (s == NULL)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", func, ft_strerror(ev));
	else
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", func, s, ft_strerror(ev));
	return (ev);
}

/*
PARAMETERS
errnmb:	the error number

DESCRIPTION
This function retrieves the error message associated with the error number
errnmb given as a parameter. If the error number is defined in the fractol.h
header file, a personalized error message is returned. If the error number is
another one, it is probably defined in the errno.h header library and the
system strerror function can give us the associated error message.

RETURN VALUE
It returns a string containing the error message associated with the error
number errnmb given as a parameter.
*/

static char	*ft_strerror(int errnmb)
{
	if (errnmb == E2SMALL)
		return (E2SMALL_MSG);
	else if (errnmb == EEMPTYF)
		return (EEMPTYF_MSG);
	else if (errnmb == EINVALF)
		return (EINVALF_MSG);
	else if (errnmb == EINVAFF)
		return (EINVAFF_MSG);
	else if (errnmb == EMACROS)
		return (EMACROS_MSG);
	else
		return (strerror(errnmb));
}

/*
PARAMETERS
p:		pointer to free
free:	free function

DESCRIPTION
This function prints an error message about the memory allocation failure on
the stderr using the function ft_print_error, which retrieves the error to
print from the value of errno; then it frees the pointer p using the function
pointed by free.

RETURN VALUE
None.
*/
void	ft_malloc_error(void *p, void (*free)(void *))
{
	ft_print_error("malloc", NULL, errno);
	if (p == NULL || free == NULL)
		return ;
	(*free)(p);
}
