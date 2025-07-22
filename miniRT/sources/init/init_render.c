/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:26:49 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:26:50 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_cam_sett	*ft_init_camera_settings(t_scene *scene);
static t_img_sett	*ft_init_image_settings(void);
static t_viewport	*ft_init_viewport(t_cam_sett *camera, t_img_sett *img_s);

t_render	*ft_init_rendering_options(t_scene *scene)
{
	t_render	*render;

	render = (t_render *) ft_calloc(1, sizeof(t_render));
	if (render == NULL)
		return (ft_malloc_error(NULL, NULL), NULL);
	render->camera = ft_init_camera_settings(scene);
	if (render->camera == NULL)
		return (free(render), NULL);
	render->img_settings = ft_init_image_settings();
	if (render->img_settings == NULL)
		return (free(render->camera), free(render), NULL);
	render->viewport = ft_init_viewport(render->camera, render->img_settings);
	if (render->viewport == NULL)
		return (free(render->img_settings), free(render->camera), \
			free(render), NULL);
	return (render);
}

static t_cam_sett	*ft_init_camera_settings(t_scene *scene)
{
	t_camera	*parsed;
	t_cam_sett	*camera;

	parsed = scene->camera;
	parsed->dir = v3_unit_vector(parsed->dir);
	camera = (t_cam_sett *) ft_calloc(1, sizeof(t_cam_sett));
	if (camera == NULL)
		return (ft_malloc_error(NULL, NULL), NULL);
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
	return (camera);
}

static t_img_sett	*ft_init_image_settings(void)
{
	t_img_sett	*img_s;

	img_s = (t_img_sett *) ft_calloc(1, sizeof(t_img_sett));
	if (img_s == NULL)
		return (ft_malloc_error(NULL, NULL), NULL);
	img_s->aspect_ratio = ((double_t) WIDTH) / ((double_t) HEIGHT);
	img_s->img_width = WIDTH;
	img_s->img_height = HEIGHT;
	img_s->samples_per_pixel = SAMPLES_PER_PIXELS;
	img_s->max_depth = MAX_DEPTH;
	if (img_s->aspect_ratio <= 0 || \
			img_s->img_width <= 0 || img_s->img_width > WIDTH_MAX || \
			img_s->img_height <= 0 || img_s->img_height > HEIGHT_MAX)
		return (ft_print_error(PROG_NAME, NULL, EMACROS), free(img_s), NULL);
	return (img_s);
}

static t_viewport	*ft_init_viewport(t_cam_sett *camera, t_img_sett *img_s)
{
	t_viewport	*viewport;
	double_t	focal_length;
	t_vector3	tmp1;

	viewport = (t_viewport *) ft_calloc(1, sizeof(t_viewport));
	if (viewport == NULL)
		return (ft_malloc_error(NULL, NULL), NULL);
	focal_length = v3_module(v3_diff(camera->lookfrom, camera->lookat));
	viewport->width = 2.0 * tan(deg_to_rad(camera->hfov) / 2) * focal_length;
	viewport->height = viewport->width / img_s->aspect_ratio;
	viewport->u = v3_scalar_prod(viewport->width, camera->u);
	viewport->v = v3_scalar_prod(viewport->height, v3_opposite(camera->v));
	viewport->pixel_delta_u = v3_scalar_div(viewport->u, img_s->img_width);
	viewport->pixel_delta_v = v3_scalar_div(viewport->v, img_s->img_height);
	tmp1 = v3_diff(camera->lookfrom, v3_scalar_prod(focal_length, camera->w));
	tmp1 = v3_diff(tmp1, v3_scalar_div(viewport->u, 2.0));
	viewport->up_left_corner = v3_diff(tmp1, v3_scalar_div(viewport->v, 2.0));
	tmp1 = v3_sum(viewport->pixel_delta_u, viewport->pixel_delta_v);
	tmp1 = v3_scalar_div(tmp1, 2.0);
	viewport->pixel_00_location = v3_sum(viewport->up_left_corner, tmp1);
	return (viewport);
}
