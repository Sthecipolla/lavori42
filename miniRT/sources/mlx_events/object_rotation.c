/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:47 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:12:57 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	plane_rotate(int keysym, t_cam_sett *set, t_plane *pl);
static void	cylinder_rotate(int keysym, t_cam_sett *set, t_cylinder *cy);

void	object_rotate(int keysym, t_data *data)
{
	t_object	*obj;
	t_cam_sett	*set;

	set = data->render->camera;
	obj = data->sel_obj;
	if (obj == NULL)
		return ;
	if (obj->type == SPHERE)
		return ;
	else if (obj->type == PLANE)
		plane_rotate(keysym, set, obj->object->plane);
	else if (obj->type == CYLINDER)
		cylinder_rotate(keysym, set, obj->object->cylinder);
	ft_render(data);
}

static void	plane_rotate(int keysym, t_cam_sett *set, t_plane *pl)
{
	if (keysym == XK_Left)
		pl->normal = v3_rotate_around_axis(pl->normal, \
			(t_vector3){0, 1, 0}, -M_PI / 36.0);
	else if (keysym == XK_Right)
		pl->normal = v3_rotate_around_axis(pl->normal, \
			(t_vector3){0, 1, 0}, M_PI / 36.0);
	else if (keysym == XK_Up)
		pl->normal = v3_rotate_around_axis(pl->normal, set->u, -M_PI / 36.0);
	else if (keysym == XK_Down)
		pl->normal = v3_rotate_around_axis(pl->normal, set->u, M_PI / 36.0);
	printf("New plane Normal:\n\t%-6.4f %-6.4f %-6.4f\n", \
		pl->normal.x, pl->normal.y, pl->normal.z);
}

static void	cylinder_rotate(int keysym, t_cam_sett *set, t_cylinder *cy)
{
	if (keysym == XK_Left)
		cy->axis = v3_rotate_around_axis(cy->axis, \
			(t_vector3){0, 1, 0}, -M_PI / 36.0);
	else if (keysym == XK_Right)
		cy->axis = v3_rotate_around_axis(cy->axis, \
			(t_vector3){0, 1, 0}, M_PI / 36.0);
	else if (keysym == XK_Up)
		cy->axis = v3_rotate_around_axis(cy->axis, set->u, -M_PI / 36.0);
	else if (keysym == XK_Down)
		cy->axis = v3_rotate_around_axis(cy->axis, set->u, M_PI / 36.0);
	printf("New plane Normal:\n\t%-6.4f %-6.4f %-6.4f\n", \
		cy->axis.x, cy->axis.y, cy->axis.z);
}
