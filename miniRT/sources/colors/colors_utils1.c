/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:02:39 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:02:39 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
PARAMETERS
trasparency:	transparency value between 0 and 255
red:			red value between 0 and 255
green:			green value between 0 and 255
blue:			blue value between 0 and 255

DESCRIPTION
This function creates a TRGB color starting from single values of transparency,
red, green, blue (each one between 0 and 255).
It uses bit shifting as each value (t, r, g, b) occupies one byte and must be
put in the correct byte of the TRGB color.

RETURN VALUE
This function returns the TRGB color.
*/
int	ft_create_trgb(int transparency, int red, int green, int blue)
{
	return (transparency << 24 | red << 16 | green << 8 | blue);
}

/*
PARAMETERS
trgb:	value of a TRGB color

DESCRIPTION
This function retrieves the transparency value from the trgb color.
It uses bit shifting as each value (t, r, g, b) occupies one byte and each one
can be retrieved by shifting trgb to the correct byte of the TRGB color.

RETURN VALUE
This function returns the transparency value of the TRGB color.
*/
int	ft_get_transparency(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

/*
PARAMETERS
trgb:	value of a TRGB color

DESCRIPTION
This function retrieves the red value from the trgb color.
It uses bit shifting as each value (t, r, g, b) occupies one byte and each one
can be retrieved by shifting trgb to the correct byte of the TRGB color.

RETURN VALUE
This function returns the red value of the TRGB color.
*/
int	ft_get_red(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

/*
PARAMETERS
trgb:	value of a TRGB color

DESCRIPTION
This function retrieves the green value from the trgb color.
It uses bit shifting as each value (t, r, g, b) occupies one byte and each one
can be retrieved by shifting trgb to the correct byte of the TRGB color.

RETURN VALUE
This function returns the green value of the TRGB color.
*/
int	ft_get_green(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

/*
PARAMETERS
trgb:	value of a TRGB color

DESCRIPTION
This function retrieves the blue value from the trgb color.
It uses bit shifting as each value (t, r, g, b) occupies one byte and each one
can be retrieved by shifting trgb to the correct byte of the TRGB color.

RETURN VALUE
This function returns the blue value of the TRGB color.
*/
int	ft_get_blue(int trgb)
{
	return (trgb & 0xFF);
}
