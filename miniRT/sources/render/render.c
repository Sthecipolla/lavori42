/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:17:16 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	ft_ray_color(t_ray ray, t_scene *scene);
static int	ft_calc_pixel(int x, int y, t_data *data);

void	ft_render(t_data *data)
{
	t_uint	x;
	t_uint	y;

	y = 0;
	while (y < data->render->img_settings->img_height)
	{
		x = 0;
		while (x < data->render->img_settings->img_width)
		{
			ft_pixel_put(&data->mlx->img, x, y, ft_calc_pixel(x, y, data));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx_session, data->mlx->mlx_window, \
		data->mlx->img.image, 0, 0);
}

static int	ft_calc_pixel(int x, int y, t_data *data)
{
	t_ray		ray;
	t_point3	pixel_center;
	t_vector3	ray_dir;
	t_vector3	tmp;

	tmp = v3_sum(v3_scalar_prod(x, data->render->viewport->pixel_delta_u), \
		v3_scalar_prod(y, data->render->viewport->pixel_delta_v));
	pixel_center = v3_sum(data->render->viewport->pixel_00_location, tmp);
	ray_dir = v3_diff(pixel_center, data->render->camera->lookfrom);
	ray = ray_init(data->render->camera->lookfrom, ray_dir);
	return (ft_ray_color(ray, data->scene));
}

/*
*/
static int	ft_ray_color(t_ray ray, t_scene *scene)
{
	t_color		color;
	t_hit		o_record;
	t_hit		l_record;
	t_object	*hit_object;
	t_light		*hit_light;

	hit_object = find_hit_object(scene, ray, &o_record);
	hit_light = find_hit_light(scene, ray, &l_record);
	if (hit_object != NULL && hit_light != NULL)
		null_farthest(&hit_object, &hit_light, l_record, o_record);
	if (hit_object != NULL && o_record.full == TRUE)
		color = calc_light(scene, &o_record, ray, hit_object);
	else if (hit_light != NULL && l_record.full == TRUE)
		color = hit_light->color;
	else
	{
		color.transparency = 0;
		color.red = 16;
		color.green = 16;
		color.blue = 16;
	}
	return (ft_create_trgb(color.transparency, color.red, \
		color.green, color.blue));
}

void	null_farthest(t_object **o, t_light **l, t_hit l_rec, t_hit o_rec)
{
	if (o_rec.t < l_rec.t)
		*l = NULL;
	else
		*o = NULL;
}
