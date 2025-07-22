/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_palettes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:02:35 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

t_color	return_palette_object(t_object *obj)
{
	static t_o_palette	num;

	if ((++num) == O_STOP)
		num = 0;
	else if (num == O_RED)
		return ((t_color){0, 255, 50, 50});
	else if (num == O_BLUE)
		return ((t_color){0, 30, 144, 255});
	else if (num == O_GREEN)
		return ((t_color){0, 34, 139, 34});
	else if (num == O_YELLOW)
		return ((t_color){0, 255, 215, 0});
	else if (num == O_PURPLE)
		return ((t_color){0, 138, 43, 226});
	else if (num == O_ORANGE)
		return ((t_color){0, 255, 140, 0});
	else if (num == O_PINK)
		return ((t_color){0, 255, 182, 193});
	else if (num == O_TEAL)
		return ((t_color){0, 0, 128, 128});
	else if (num == O_CYAN)
		return ((t_color){0, 0, 255, 255});
	else if (num == O_MAGENTA)
		return ((t_color){0, 255, 0, 255});
	return (obj->def_color);
}

t_color	return_palette_light(t_light *light)
{
	static t_l_palette	num;

	if ((++num) == L_STOP)
		num = 0;
	else if (num == L_WHITE)
		return ((t_color){0, 255, 255, 255});
	else if (num == L_WARM_WHITE)
		return ((t_color){0, 255, 248, 220});
	else if (num == L_COOL_WHITE)
		return ((t_color){0, 248, 248, 255});
	else if (num == L_RED)
		return ((t_color){0, 255, 100, 100});
	else if (num == L_BLUE)
		return ((t_color){0, 100, 149, 237});
	else if (num == L_GREEN)
		return ((t_color){0, 144, 238, 144});
	else if (num == L_PURPLE)
		return ((t_color){0, 221, 160, 221});
	else if (num == L_ORANGE)
		return ((t_color){0, 255, 218, 185});
	else if (num == L_CYAN)
		return ((t_color){0, 224, 255, 255});
	else if (num == L_MAGENTA)
		return ((t_color){0, 255, 192, 203});
	return (light->def_color);
}

t_color	return_palette_ambient(t_ambient *amb)
{
	static t_l_palette	num;

	if ((++num) == L_STOP)
		num = 0;
	else if (num == L_WHITE)
		return ((t_color){0, 255, 255, 255});
	else if (num == L_WARM_WHITE)
		return ((t_color){0, 255, 248, 220});
	else if (num == L_COOL_WHITE)
		return ((t_color){0, 248, 248, 255});
	else if (num == L_RED)
		return ((t_color){0, 255, 100, 100});
	else if (num == L_BLUE)
		return ((t_color){0, 100, 149, 237});
	else if (num == L_GREEN)
		return ((t_color){0, 144, 238, 144});
	else if (num == L_PURPLE)
		return ((t_color){0, 221, 160, 221});
	else if (num == L_ORANGE)
		return ((t_color){0, 255, 218, 185});
	else if (num == L_CYAN)
		return ((t_color){0, 224, 255, 255});
	else if (num == L_MAGENTA)
		return ((t_color){0, 255, 192, 203});
	return (amb->def_color);
}
