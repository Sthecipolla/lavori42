/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 18:21:26 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/19 15:20:33 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <errors/minishell_errors.h>

static int	is_directory(const char *path);

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
int	ft_print_error(char *func, char *s)
{
	int	ev;

	ev = errno;
	if (s == NULL)
		ft_dprintf(STDERR_FILENO, "%s: %s\n", func, ft_strerror(ev));
	else
		ft_dprintf(STDERR_FILENO, "%s: %s: %s\n", func, s, ft_strerror(ev));
	if (ev != errno)
		perror("write");
	errno = ev;
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
char	*ft_strerror(int errnmb)
{
	if (errnmb == E2SMALL)
		return (E2SMALL_MSG);
	else if (errnmb == ENOCMD)
		return (ENOCMD_MSG);
	else if (errnmb == EAMBRED)
		return (EAMBRED_MSG);
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
	errno = ft_print_error("malloc", NULL);
	if (p == NULL || free == NULL)
		return ;
	(*free)(p);
}

/*
*/
int	ft_print_cmd_error(t_cmd_table *cmd)
{
	int	errsv;

	if (errno == ENOENT && ft_strchr(cmd->args[0], '/') == NULL)
		errno = ENOCMD;
	if (cmd->args != NULL)
	{
		if (errno == EACCES && ft_strchr(cmd->args[0], '/') == NULL)
			errno = ENOCMD;
		if (is_directory(cmd->args[0]) == TRUE)
			errno = EISDIR;
		if (errno == EACCES || errno == EISDIR || errno == ENOENT)
			ft_print_error(PROG_NAME, cmd->args[0]);
		else if (cmd->args[0] != NULL && cmd->args[0][0] != '\0')
			ft_print_error(cmd->args[0], NULL);
		else
			ft_print_error("\'\'", NULL);
	}
	if (errno == ENOCMD || errno == ENOENT)
		errsv = ERR_NOTFOUND;
	else if (errno == EACCES || errno == EISDIR)
		errsv = ERR_PERM;
	else
		errsv = errno;
	return (errsv);
}

static int	is_directory(const char *path)
{
	struct stat	buf;
	int			errsv;

	errsv = errno;
	if (stat(path, &buf) == 0)
		return (S_ISDIR(buf.st_mode));
	errno = errsv;
	return (FALSE);
}
