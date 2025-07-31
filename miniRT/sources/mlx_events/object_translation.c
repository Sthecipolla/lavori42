/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	sphere_translate(int keysym, t_cam_sett *set, t_sphere *sp);
static void	plane_translate(int keysym, t_cam_sett *set, t_plane *pl);
static void	cylinder_translate(int keysym, t_cam_sett *set, t_cylinder *cy);

void	object_translate(int keysym, t_data *data)
{
	t_object	*obj;
	t_cam_sett	*set;

	set = data->render->camera;
	obj = data->sel_obj;
	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
		sphere_translate(keysym, set, obj->object->sphere);
	else if (obj->type == PLANE)
		plane_translate(keysym, set, obj->object->plane);
	else if (obj->type == CYLINDER)
		cylinder_translate(keysym, set, obj->object->cylinder);
	ft_render(data);
}

static void	sphere_translate(int keysym, t_cam_sett *set, t_sphere *sp)
{
	if (keysym == XK_w)
		sp->center = v3_sum(sp->center, v3_opposite(set->w));
	else if (keysym == XK_a)
		sp->center = v3_sum(sp->center, v3_opposite(set->u));
	else if (keysym == XK_s)
		sp->center = v3_sum(sp->center, set->w);
	else if (keysym == XK_d)
		sp->center = v3_sum(sp->center, set->u);
	else if (keysym == XK_Shift_L)
		sp->center = v3_sum(sp->center, v3_opposite(set->v));
	else if (keysym == XK_space)
		sp->center = v3_sum(sp->center, set->v);
	printf("New sphere Coordinates:\n\t%-6.4f %-6.4f %-6.4f\n", \
		sp->center.x, sp->center.y, sp->center.z);
}

static void	plane_translate(int keysym, t_cam_sett *set, t_plane *pl)
{
	if (keysym == XK_w)
		pl->point = v3_sum(pl->point, v3_opposite(set->w));
	else if (keysym == XK_a)
		pl->point = v3_sum(pl->point, v3_opposite(set->u));
	else if (keysym == XK_s)
		pl->point = v3_sum(pl->point, set->w);
	else if (keysym == XK_d)
		pl->point = v3_sum(pl->point, set->u);
	else if (keysym == XK_Shift_L)
		pl->point = v3_sum(pl->point, v3_opposite(set->v));
	else if (keysym == XK_space)
		pl->point = v3_sum(pl->point, set->v);
	printf("New plane Coordinates:\n\t%-6.4f %-6.4f %-6.4f\n", \
		pl->point.x, pl->point.y, pl->point.z);
}

static void	cylinder_translate(int keysym, t_cam_sett *set, t_cylinder *cy)
{
	if (keysym == XK_w)
		cy->center = v3_sum(cy->center, v3_opposite(set->w));
	else if (keysym == XK_a)
		cy->center = v3_sum(cy->center, v3_opposite(set->u));
	else if (keysym == XK_s)
		cy->center = v3_sum(cy->center, set->w);
	else if (keysym == XK_d)
		cy->center = v3_sum(cy->center, set->u);
	else if (keysym == XK_Shift_L)
		cy->center = v3_sum(cy->center, v3_opposite(set->v));
	else if (keysym == XK_space)
		cy->center = v3_sum(cy->center, set->v);
	printf("New cylinder Coordinates:\n\t%-6.4f %-6.4f %-6.4f\n", \
		cy->center.x, cy->center.y, cy->center.z);
}

void	light_translate(int keysym, t_data *data)
{
	t_light		*light;
	t_cam_sett	*set;

	set = data->render->camera;
	light = data->sel_light;
	if (light == NULL)
		return ;
	if (keysym == XK_w)
		light->point = v3_sum(light->point, v3_opposite(set->w));
	else if (keysym == XK_a)
		light->point = v3_sum(light->point, v3_opposite(set->u));
	else if (keysym == XK_s)
		light->point = v3_sum(light->point, set->w);
	else if (keysym == XK_d)
		light->point = v3_sum(light->point, set->u);
	else if (keysym == XK_Shift_L)
		light->point = v3_sum(light->point, v3_opposite(set->v));
	else if (keysym == XK_space)
		light->point = v3_sum(light->point, set->v);
	printf("New light Coordinates:\n\t%-6.4f %-6.4f %-6.4f\n", \
		light->point.x, light->point.y, light->point.z);
	ft_render(data);
}
