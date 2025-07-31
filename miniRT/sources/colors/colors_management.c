/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:02:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:02:31 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
PARAMETERS
img:	pointer to a structure that contains an image
x:		coordinate on the image about the horizontal axis
y:		coordinate on the image about the vertical axis
color:	integer which represents the color used to fill the pixel
		at coordinates (x,y) with

DESCRIPTION
This function fills the pixel of the image img at coordinates (x,y) with the
color color. 

RETURN VALUE
None.

EXPLANATION
The image is a contiguos memory area, where every line is situated after the
previous one. img->addr is a pointer to the first byte of this memory area.
Each pixel of the image is a memory area of img->bpp bits (it is as long as an
integer, almost surely 32 bits). Each line is long img->line_len bytes, which
can be longer than the width of the image times the number of bytes per pixel.
If the pixel to fill as coordinates (x,y), to obtain a pointer to the first
byte of that pixel I have to skip y lines (so a total of y * img->line_len 
bytes), then another x pixels (so anothers x * (img->bpp / 8) bytes); adding
this number to the img->addr pointer gives me a pointer to the pixel to fill.
Then, I fills it with the color value.
*/
void	ft_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dest = color;
}

/*
PARAMETERS
img:	pointer to a structure that contains an image
x:		coordinate on the image about the horizontal axis
y:		coordinate on the image about the vertical axis

DESCRIPTION
This function retrives the color of the pixel at coordinates (x,y) from the
image img. 

RETURN VALUE
None.

EXPLANATION
See explanation of the function ft_pixel_put.
*/
int	ft_get_pixel_color(t_image *img, int x, int y)
{
	char	*dest;

	dest = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)dest);
}
