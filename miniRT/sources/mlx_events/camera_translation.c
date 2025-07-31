/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:29 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:13:32 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	ft_update_camera_translation(t_data *data);

void	camera_translate(int keysym, t_data *data)
{
	t_camera	*cam;
	t_cam_sett	*set;

	cam = data->scene->camera;
	set = data->render->camera;
	if (keysym == XK_w)
		cam->point = v3_sum(cam->point, v3_opposite(set->w));
	else if (keysym == XK_a)
		cam->point = v3_sum(cam->point, v3_opposite(set->u));
	else if (keysym == XK_s)
		cam->point = v3_sum(cam->point, set->w);
	else if (keysym == XK_d)
		cam->point = v3_sum(cam->point, set->u);
	else if (keysym == XK_Shift_L)
		cam->point = v3_sum(cam->point, v3_opposite(set->v));
	else if (keysym == XK_space)
		cam->point = v3_sum(cam->point, set->v);
	printf("New camera Coordinates:\t%.4f %.4f %.4f\n", cam->point.x, \
		cam->point.y, cam->point.z);
	ft_update_camera_translation(data);
	ft_render(data);
}

static void	ft_update_camera_translation(t_data *data)
{
	t_camera	*parsed;
	t_cam_sett	*camera;

	parsed = data->scene->camera;
	camera = data->render->camera;
	camera->lookfrom = parsed->point;
	camera->lookat = v3_sum(parsed->point, parsed->dir);
	ft_update_vp(camera, data->render->img_settings, data->render->viewport);
}
