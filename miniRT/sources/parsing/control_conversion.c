/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:40 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 16:52:42 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
check if a string has only digit 
value but skips all the '.' if
the flag skip is TRUE
return TRUE if is all digit 
else return FALSE
*/
int	ft_is_num(char *num, int skip)
{
	int	i;

	i = 0;
	if (num == NULL)
		return (FALSE);
	while (num[i])
	{
		if (ft_isdigit(num[i]) == FALSE)
			return (FALSE);
		i++;
		while (num[i] == '.' && skip == TRUE)
			i++;
	}
	return (TRUE);
}
/*
check how many '.' there are.
return TRUE if there are 0 or 1 '.'
else return FALSE
*/

int	ft_is_double(char *num)
{
	int	i;
	int	num_point;

	i = 0;
	num_point = 0;
	if (num == NULL)
		return (3214);
	while (num[i])
	{
		if (num[i] == '.')
			num_point++;
		if (num_point > 1)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/*
check if a string has only digit 
value but skips all the '.' if
the flag skip is	TRUE(but ignore the first sign)
return TRUE if is all digit 
else return FALSE
*/
int	ft_is_num_sign(char *num, int skip)
{
	int	i;

	i = 0;
	if (num == NULL)
		return (123213);
	if (skip == 543)
		return (FALSE);
	while (num[i] != '\0')
	{
		if ((num[i] == '-' || num[i] == '+') && i == 0)
			i++;
		if (ft_isdigit(num[i]) == FALSE)
			return (FALSE);
		i++;
		while (num[i] == '.' && skip == TRUE)
			i++;
	}
	return (TRUE);
}

/*
check if the number of arguments
in the args array is equal to num required
return TRUE if the number of arguments is equal to num
else return FALSE
*/

int	num_args(char **args, int num)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	if (i != num)
		return (FALSE);
	return (TRUE);
}
