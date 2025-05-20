/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 09:44:18 by daromoli          #+#    #+#             */
/*   Updated: 2025/02/16 21:00:18 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isinset(char c, char const *set);
static int	print_conversion(int fd, va_list *args, char c);

/*
PARAMETERS
str:	The string to print.
...:	All the arguments to print within the string str.

DESCRIPTION
This function prints the string str on the standard output.
It handles the following convertions: cspdiuxX%.
%c --> 	prints the charcacter from the corrisponding argument
%s --> 	prints the string from the corrisponding argument
%p --> 	prints the memory address of the pointer from the corrisponding
		argument in hexadecimal form
%d --> 	prints the decimal number from the corrisponding argument
%i --> 	prints the decimal number from the corrisponding argument
%u --> 	prints the unsigned decimal number from the corrisponding argument
%x --> 	prints the hexadecimal number from the corrisponding argument in
		lowercase format
%X --> 	prints the hexadecimal number from the corrisponding argument in
		uppercase format
%% -->	prints a percent sign

RETURN VALUE
This function returns the number of charcaters printed (count).
It returns ERROR = -1 if the print failed.

EXPLANATION
This function is a variadic function, so it defines a list of arguments using
the type va_list defined in stdarg.h, that is a list of variable length which
contains the argument passed to the function in place of the three dots.
The list args is inizialized with the function va_start, and it is ended with
the function va_end. va_start needs also the last mandatory parameter of the
function (str), so it knows what is the first argument to include in the list.
The function va_arg (used inside print_conversion) retrieves the current argu-
ment from the list based on the type specified and then goes to the next one.
The number of characters printed (count) is initialized to 0.
Then a while loop is started until the end of the string str is found. The
characters which are not a % sign are printed until a % sign is found. When a
% sign is found in the string, a conversion is performed using the funtion
print_conversion. If the character after the % is not one of the supported
convertions, the % sign is printed and the print continues normally.
All the printed characters are added to count, and finally count is returned.
If an error occurs at any moment, so tmp_count = ERROR = -1, then ERROR = -1
is returned and the execution stops.
*/
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		tmp_count;

	if (str == NULL)
		return (ERROR);
	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			tmp_count = print_conversion(STDOUT_FILENO, &args, *(++str));
			if (ft_isinset(*str, "cspdiuxX%%") == TRUE)
				str++;
		}
		else
			tmp_count = ft_put_char(STDOUT_FILENO, *str++);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
	}
	va_end(args);
	return (count);
}

/*
PARAMETERS
fd:		The file descriptor to write to.
str:	The string to print.
...:	All the arguments to print within the string str.

DESCRIPTION
This function prints the string str in the file descripted by fd.
It handles the following convertions: cspdiuxX%.
%c --> 	prints the charcacter from the corrisponding argument
%s --> 	prints the string from the corrisponding argument
%p --> 	prints the memory address of the pointer from the corrisponding
		argument in hexadecimal form
%d --> 	prints the decimal number from the corrisponding argument
%i --> 	prints the decimal number from the corrisponding argument
%u --> 	prints the unsigned decimal number from the corrisponding argument
%x --> 	prints the hexadecimal number from the corrisponding argument in
		lowercase format
%X --> 	prints the hexadecimal number from the corrisponding argument in
		uppercase format
%% -->	prints a percent sign

RETURN VALUE
This function returns the number of charcaters printed (count).
It returns ERROR = -1 if the print failed.

EXPLANATION
This function is a variadic function, so it defines a list of arguments using
the type va_list defined in stdarg.h, that is a list of variable length which
contains the argument passed to the function in place of the three dots.
The list args is inizialized with the function va_start, and it is ended with
the function va_end. va_start needs also the last mandatory parameter of the
function (str), so it knows what is the first argument to include in the list.
The function va_arg (used inside print_conversion) retrieves the current argu-
ment from the list based on the type specified and then goes to the next one.
The number of characters printed (count) is initialized to 0.
Then a while loop is started until the end of the string str is found. The
characters which are not a % sign are printed until a % sign is found. When a
% sign is found in the string, a conversion is performed using the funtion
print_conversion. If the character after the % is not one of the supported
convertions, the % sign is printed and the print continues normally.
All the printed characters are added to count, and finally count is returned.
If an error occurs at any moment, so tmp_count = ERROR = -1, then ERROR = -1
is returned and the execution stops.
*/
int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		count;
	int		tmp_count;

	if (str == NULL)
		return (ERROR);
	va_start(args, str);
	count = 0;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			tmp_count = print_conversion(fd, &args, *(++str));
			if (ft_isinset(*str, "cspdiuxX%%") == TRUE)
				str++;
		}
		else
			tmp_count = ft_put_char(fd, *str++);
		if (tmp_count == ERROR)
			return (ERROR);
		count += tmp_count;
	}
	va_end(args);
	return (count);
}

/*
PARAMETERS
fd:		The file descriptor to write to.
args:	A pointer to the list of optional arguments of ft_printf.
c:		The character specifing the conversion which has to be performed,
		which is the one after the % sign in the original string.

DESCRIPTION
This function converts the current argument of the list contained in args
to the type specified by c, and prints it on the standard output. It also
counts the number of characters printed.

RETURN VALUE
This function returns the number of charcaters printed (count).
It returns ERROR = -1 if the print failed.

EXPLANATION
For each conversion, this function calls another function which converts
the argument to the type specified and prints it on the standard output,
returning the number of characters printed.
The function va_arg retrieves the current argument from the list args based
on the type specified as second argument, and then goes to the next one.
The conversion supported and printed by this function are:
c	-->	Prints a character. The type of the argument is int and not char
		because va_arg has undefined behaviors with char (char is a promotable
		type and will be promoted to int by va_arg, with possible trespassing
		into the memory area not assigned to the char).
s	-->	Prints a string or (null) if the string doesn't exist. The type of the
		argument is char *.
p	-->	Prints the memory address of a void pointer or (nil) if the pointer is
		NULL. The type of the argument is void *.
d	-->	Prints a decimal number. The type of the argument is int.
i	-->	Prints a decimal number. The type of the argument is int.
u	-->	Prints an unsigned decimal number. The type of the arg is unsigned int.
x	-->	Prints an hexadecimal number in the lowercase format. The type of the
		argument is unsigned int because negative number are not printed and
		overflow also in the original printf function.
X	-->	Prints an hexadecimal number in the uppercase format. The type of the
		argument is unsigned int because negative number are not printed and
		overflow also in the original printf function.
%	-->	Prints the % sign.
In all other cases the % sign is printed because the charatecter c does not
represent a supported conversion, so everything should be printed as it is.
When c is not a supported conversion, the print of the characters after the %
sign is implemented in the ft_printf function.
\0	-->	The % sign which indicates a conversion is the last charcater of the
		string. The original printf does not print it and returns -1, and so
		does the function: nothing is printed and ERROR = -1 is returned.
*/
static int	print_conversion(int fd, va_list *args, char c)
{
	if (c == 'c')
		return (ft_put_char(fd, (char)va_arg(*args, int)));
	else if (c == 's')
		return (ft_put_string(fd, va_arg(*args, char *)));
	else if (c == 'p')
		return (ft_put_address(fd, va_arg(*args, void *)));
	else if (c == 'd')
		return (ft_put_int_base(fd, va_arg(*args, int), DEC_BASE));
	else if (c == 'i')
		return (ft_put_int_base(fd, va_arg(*args, int), DEC_BASE));
	else if (c == 'u')
		return (ft_put_unsigned_int_base(fd, \
			va_arg(*args, unsigned int), DEC_BASE));
	else if (c == 'x')
		return (ft_put_unsigned_int_base(fd, \
			va_arg(*args, unsigned int), HEX_LOWERCASE_BASE));
	else if (c == 'X')
		return (ft_put_unsigned_int_base(fd, \
			va_arg(*args, unsigned int), HEX_UPPERCASE_BASE));
	else if (c == '%')
		return (ft_put_char(fd, '%'));
	else if (c == '\0')
		return (ERROR);
	else
		return (ft_put_char(fd, '%'));
}

/*
PARAMETERS
c:		The character to check.
set:	The set of charcaters to compare with c.

DESCRIPTION
This function checks if the character c is present among all the characters
in the string set.

RETURN VALUE
TRUE = 1 if c is in the set, FALSE = 0 if it is not.
*/
static int	ft_isinset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (c == set[i])
			return (TRUE);
		i++;
	}
	return (FALSE);
}
