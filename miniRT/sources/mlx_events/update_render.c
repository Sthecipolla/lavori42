/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:05:57 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:05:57 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	ft_update_rendering_options(t_render *render, t_scene *scene)
{
	if (render == NULL)
		return ;
	ft_update_camera_settings(render->camera, scene);
	ft_update_vp(render->camera, render->img_settings, render->viewport);
}

void	ft_update_camera_settings(t_cam_sett *camera, t_scene *scene)
{
	t_camera	*parsed;

	parsed = scene->camera;
	parsed->dir = v3_unit_vector(parsed->dir);
	camera->lookfrom = parsed->point;
	camera->lookat = v3_sum(parsed->point, parsed->dir);
	if (ft_are_double_equal(fabs(parsed->dir.y), 1.0, EPSILON9) == FALSE)
		camera->vector_up = (t_vector3){0, 1, 0};
	else
		camera->vector_up = (t_vector3){0, 0, 1};
	camera->w = v3_unit_vector(v3_diff(camera->lookfrom, camera->lookat));
	camera->u = v3_unit_vector(v3_cross_prod(camera->vector_up, camera->w));
	camera->v = v3_cross_prod(camera->w, camera->u);
	camera->hfov = parsed->fov;
}

void	ft_update_vp(t_cam_sett *cam, t_img_sett *img_s, t_viewport *vp)
{
	double_t	focal_length;
	t_vector3	tmp1;

	focal_length = v3_module(v3_diff(cam->lookfrom, cam->lookat));
	vp->width = 2.0 * tan(deg_to_rad(cam->hfov) / 2) * focal_length;
	vp->height = vp->width / img_s->aspect_ratio;
	vp->u = v3_scalar_prod(vp->width, cam->u);
	vp->v = v3_scalar_prod(vp->height, v3_opposite(cam->v));
	vp->pixel_delta_u = v3_scalar_div(vp->u, img_s->img_width);
	vp->pixel_delta_v = v3_scalar_div(vp->v, img_s->img_height);
	tmp1 = v3_diff(cam->lookfrom, v3_scalar_prod(focal_length, cam->w));
	tmp1 = v3_diff(tmp1, v3_scalar_div(vp->u, 2.0));
	vp->up_left_corner = v3_diff(tmp1, v3_scalar_div(vp->v, 2.0));
	tmp1 = v3_sum(vp->pixel_delta_u, vp->pixel_delta_v);
	tmp1 = v3_scalar_div(tmp1, 2.0);
	vp->pixel_00_location = v3_sum(vp->up_left_corner, tmp1);
}
