/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:54 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

#define LIGHT_DIAMETER	0.2
#define SHADOW_BIAS		0.001

static t_light	*single_light(t_scene *scene, t_ray ray, t_hit *rec, t_uint i);
static bool		is_behind_obj(t_scene *scene, t_light *light);

t_light	*find_hit_light(t_scene *scene, t_ray ray, t_hit *record)
{
	t_uint	i;
	t_hit	alt_record;
	t_light	*closest_light;
	t_light	*tmp_light;

	if (record == NULL)
		record = &alt_record;
	closest_light = NULL;
	record->full = FALSE;
	i = 0;
	while (i < scene->num_lights)
	{
		tmp_light = single_light(scene, ray, record, i);
		if (tmp_light != NULL)
			closest_light = tmp_light;
		i++;
	}
	return (closest_light);
}

static t_light	*single_light(t_scene *scene, t_ray ray, t_hit *rec, t_uint i)
{
	t_light	*hit_light;
	t_hit	tmp_record;
	t_light	*light;
	bool	ret;

	hit_light = NULL;
	tmp_record.full = FALSE;
	light = &scene->lights[i];
	if (is_behind_obj(scene, light) == TRUE)
		return (NULL);
	ret = hit_sphere(light->point, LIGHT_DIAMETER, ray, &tmp_record);
	if (ret == TRUE && (rec->full == FALSE || tmp_record.t < rec->t))
	{
		copy_hit_record(&tmp_record, rec);
		hit_light = light;
	}
	return (hit_light);
}

/*
DESCRIPTION
This function verifies if the light is behind an object as seen from the camera.
This is needed because the light on the screen is represented as a sphere, and
sometimes it happens that the center of the sphere is behind an object, so it
does not illuminate the face of the object seen from the camera, but part of the
sphere is still visible. When that happens, I don't want to show the sphere.
It works similarly to the function is_in_shadow in the file lighting.c.
*/
static bool	is_behind_obj(t_scene *scene, t_light *light)
{
	t_ray		ray;
	t_hit		hit;
	double_t	dist;

	ray.dir = v3_unit_vector(v3_diff(light->point, scene->camera->point));
	ray.origin = scene->camera->point;
	hit.full = FALSE;
	dist = v3_dist(scene->camera->point, light->point);
	if (hit_anything(scene, ray, &hit) == TRUE)
	{
		if (hit.t < dist - SHADOW_BIAS)
			return (TRUE);
	}
	return (FALSE);
}
