/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:25 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:13:19 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_update_camera_rotation(t_data *data, int keysym);
static void	ft_update_camera_y_rotation(t_data *data, int keysym);
static void	ft_update_not_360(t_data *data, int keysym);
static void	ft_update_normal_rot(t_data *data, int keysym);

void	camera_rotate(int keysym, t_data *data)
{
	t_camera	*cam;

	cam = data->scene->camera;
	if (ft_are_double_equal(fabs(cam->dir.y), 1.0, EPSILON9) == TRUE && \
			(keysym == XK_Left || keysym == XK_Right))
		ft_update_camera_y_rotation(data, keysym);
	else if (fabs(cam->dir.y) > 0.99 && (keysym == XK_Down || keysym == XK_Up))
		ft_update_not_360(data, keysym);
	else
		ft_update_normal_rot(data, keysym);
	printf("New camera Direction:\t%.4f %.4f %.4f\n", cam->dir.x, \
		cam->dir.y, cam->dir.z);
	ft_render(data);
}

static void	ft_update_camera_rotation(t_data *data, int keysym)
{
	t_cam_sett	*camera;

	if (data == NULL || data->render == NULL)
		return ;
	camera = data->render->camera;
	if (keysym == XK_Up || keysym == XK_Down)
	{
		camera->lookfrom = data->scene->camera->point;
		camera->lookat = v3_sum(data->scene->camera->point, \
			data->scene->camera->dir);
		camera->w = v3_unit_vector(v3_diff(camera->lookfrom, camera->lookat));
		camera->u = camera->u;
		camera->v = v3_cross_prod(camera->w, camera->u);
	}
	else if (keysym == XK_Left || keysym == XK_Right)
		ft_update_camera_settings(camera, data->scene);
	ft_update_vp(camera, data->render->img_settings, data->render->viewport);
}

static void	ft_update_camera_y_rotation(t_data *data, int keysym)
{
	t_cam_sett	*set;

	set = data->render->camera;
	set->w = set->w;
	if (keysym == XK_Left)
		set->u = v3_rotate_around_axis(set->u, set->w, M_PI / 36.0);
	else if (keysym == XK_Right)
		set->u = v3_rotate_around_axis(set->u, set->w, -M_PI / 36.0);
	set->v = v3_cross_prod(set->w, set->u);
	ft_update_vp(set, data->render->img_settings, data->render->viewport);
}

static void	ft_update_not_360(t_data *data, int keysym)
{
	t_camera	*cam;
	t_cam_sett	*set;

	cam = data->scene->camera;
	set = data->render->camera;
	if (keysym == XK_Down && cam->dir.y > -0.99)
		cam->dir = v3_rotate_around_axis(cam->dir, set->u, -M_PI / 36.0);
	else if (keysym == XK_Down)
		cam->dir = (t_vector3){0, -1, 0};
	else if (keysym == XK_Up && cam->dir.y < 0.99)
		cam->dir = v3_rotate_around_axis(cam->dir, set->u, M_PI / 36.0);
	else if (keysym == XK_Up)
		cam->dir = (t_vector3){0, 1, 0};
	ft_update_camera_rotation(data, keysym);
}

static void	ft_update_normal_rot(t_data *data, int keysym)
{
	t_camera	*cam;
	t_cam_sett	*set;

	cam = data->scene->camera;
	set = data->render->camera;
	if (keysym == XK_Left)
		cam->dir = v3_rotate_around_axis(cam->dir, \
			(t_vector3){0, 1, 0}, M_PI / 36.0);
	else if (keysym == XK_Right)
		cam->dir = v3_rotate_around_axis(cam->dir, \
			(t_vector3){0, 1, 0}, -M_PI / 36.0);
	else if (keysym == XK_Up)
		cam->dir = v3_rotate_around_axis(cam->dir, set->u, M_PI / 36.0);
	else if (keysym == XK_Down)
		cam->dir = v3_rotate_around_axis(cam->dir, set->u, -M_PI / 36.0);
	ft_update_camera_rotation(data, keysym);
}
