/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:02:43 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:04:08 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

/*
DESCRIPTION
Utility functions per operazioni sui colori
*/
t_color	color_multiply(t_color c1, t_color c2)
{
	t_color	result;

	result.red = (t_chan)(((double_t) c1.red * c2.red) / 255.0);
	result.green = (t_chan)(((double_t) c1.green * c2.green) / 255.0);
	result.blue = (t_chan)(((double_t) c1.blue * c2.blue) / 255.0);
	result.transparency = c1.transparency;
	return (result);
}

t_color	color_add(t_color c1, t_color c2)
{
	t_color	result;

	result.red = (t_chan)(fmin(255, c1.red + c2.red));
	result.green = (t_chan)(fmin(255, c1.green + c2.green));
	result.blue = (t_chan)(fmin(255, c1.blue + c2.blue));
	result.transparency = c1.transparency;
	return (result);
}

t_color	color_scale(t_color color, double_t scale)
{
	t_color	result;

	result.red = (t_chan)(fmin(255, color.red * scale));
	result.green = (t_chan)(fmin(255, color.green * scale));
	result.blue = (t_chan)(fmin(255, color.blue * scale));
	result.transparency = color.transparency;
	return (result);
}
