/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_obj_properties.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:36 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:12:06 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	cyl(int keysym, t_object *cyl);
static void	pla(int keysym, t_object *pla);
static void	sph(int keysym, t_object *sph);
static void	print_info(int keysym, t_obj_type t, double_t v, t_color c);

void	object_change(int keysym, t_data *data)
{
	if (data->sel_obj == NULL)
		return ;
	if (data->sel_obj->type == CYLINDER)
		cyl(keysym, data->sel_obj);
	else if (data->sel_obj->type == PLANE)
		pla(keysym, data->sel_obj);
	else if (data->sel_obj->type == SPHERE)
		sph(keysym, data->sel_obj);
	ft_render(data);
}

static void	cyl(int keysym, t_object *cyl)
{
	if (keysym == XK_1)
		cyl->object->cylinder->diameter += 1.0;
	else if (keysym == XK_2)
	{
		cyl->object->cylinder->diameter -= 1.0;
		if (cyl->object->cylinder->diameter < 1.0)
			cyl->object->cylinder->diameter = 1.0;
	}
	else if (keysym == XK_3)
		cyl->object->cylinder->height += 1.0;
	else if (keysym == XK_4)
	{
		cyl->object->cylinder->height -= 1.0;
		if (cyl->object->cylinder->height < 1.0)
			cyl->object->cylinder->height = 1.0;
	}
	else if (keysym == XK_c)
		cyl->object->cylinder->color = return_palette_object(cyl);
	if (keysym == XK_3 || keysym == XK_4)
		print_info(keysym, CYLINDER, cyl->object->cylinder->height, \
			cyl->object->cylinder->color);
	else
		print_info(keysym, CYLINDER, cyl->object->cylinder->diameter, \
			cyl->object->cylinder->color);
}

static void	pla(int keysym, t_object *pla)
{
	if (keysym == XK_c)
		pla->object->plane->color = return_palette_object(pla);
	print_info(keysym, PLANE, 0, pla->object->plane->color);
}

static void	sph(int keysym, t_object *sph)
{
	if (keysym == XK_1)
		sph->object->sphere->diameter += 1.0;
	else if (keysym == XK_2)
	{
		sph->object->sphere->diameter -= 1.0;
		if (sph->object->sphere->diameter < 1.0)
			sph->object->sphere->diameter = 1.0;
	}
	else if (keysym == XK_c)
		sph->object->sphere->color = return_palette_object(sph);
	print_info(keysym, SPHERE, sph->object->sphere->diameter, \
		sph->object->sphere->color);
}

static void	print_info(int keysym, t_obj_type t, double_t v, t_color c)
{
	if (t == SPHERE && (keysym == XK_1 || keysym == XK_2))
		printf("New sphere diameter: %.4f\n", v);
	else if (t == CYLINDER && (keysym == XK_1 || keysym == XK_2))
		printf("New cylinder diameter: %.4f\n", v);
	else if (t == CYLINDER && (keysym == XK_3 || keysym == XK_4))
		printf("New cylinder height: %.4f\n", v);
	else if (t == SPHERE && keysym == XK_c)
		printf("New sphere color:\n\tr: %3d\tg: %3d\tb: %3d\n", c.red, \
			c.green, c.blue);
	else if (t == PLANE && keysym == XK_c)
		printf("New plane color:\n\tr: %3d\tg: %3d\tb: %3d\n", c.red, \
			c.green, c.blue);
	else if (t == CYLINDER && keysym == XK_c)
		printf("New cylinder color:\n\tr: %3d\tg: %3d\tb: %3d\n", c.red, \
			c.green, c.blue);
}
