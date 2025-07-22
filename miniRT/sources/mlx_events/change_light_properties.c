/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_light_properties.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:33 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	print_info(int keysym, char *s, double_t ratio, t_color color);

void	light_change(int keysym, t_data *data)
{
	t_light	*light;

	light = data->sel_light;
	if (light == NULL)
		return ;
	if (keysym == XK_1)
	{
		light->ratio += 0.05;
		if (light->ratio > 1.0)
			light->ratio = 1.0;
	}
	else if (keysym == XK_2)
	{
		light->ratio -= 0.05;
		if (light->ratio < 0.0)
			light->ratio = 0.0;
	}
	else if (keysym == XK_c)
		light->color = return_palette_light(light);
	print_info(keysym, "light", light->ratio, light->color);
	ft_render(data);
}

void	ambient_change(int keysym, t_data *data)
{
	t_ambient	*amb;

	amb = data->scene->ambient;
	if (data->sel_amb == FALSE || amb == NULL)
		return ;
	if (keysym == XK_1)
	{
		amb->ratio += 0.05;
		if (amb->ratio > 1.0)
			amb->ratio = 1.0;
	}
	else if (keysym == XK_2)
	{
		amb->ratio -= 0.05;
		if (amb->ratio < 0.0)
			amb->ratio = 0.0;
	}
	else if (keysym == XK_c)
		amb->color = return_palette_ambient(amb);
	print_info(keysym, "ambient light", amb->ratio, amb->color);
	ft_render(data);
}

static void	print_info(int keysym, char *s, double_t ratio, t_color color)
{
	if (keysym == XK_1 || keysym == XK_2)
		printf("New %s ratio: %.2f\n", s, ratio);
	else if (keysym == XK_c)
		printf("New %s color:\n\tr: %3d\tg: %3d\tb: %3d\n", s, color.red, \
			color.green, color.blue);
}
