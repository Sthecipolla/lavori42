/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_anything.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:16:26 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:16:26 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

//bool	hit_cylinder(){return FALSE;}

/* bool	hit_anything(t_scene *scene, t_ray ray, t_hit *record)
{
	t_uint		i;
	t_object	obj;
	t_hit		tmp_record;
	t_uint		count;
	bool		ret;

	count = 0;
	tmp_record.full = FALSE;
	i = 0;
	while (i < scene->num_objects)
	{
		obj = scene->objects[i];
		ret = FALSE;
		if (obj.type == SPHERE)
			ret = hit_sphere(obj.object->sphere->center, \
				0.5 * obj.object->sphere->diameter, ray, &tmp_record);
		else if (obj.type == PLANE)
			ret = hit_plane(obj.object->plane->point, \
				obj.object->plane->normal, ray, &tmp_record);
		else if (obj.type == CYLINDER)
			ret = hit_cylinder(obj.object->cylinder, ray, &tmp_record);
		if (ret == TRUE && (record->full == FALSE || tmp_record.t < record->t))
			copy_hit_record(&tmp_record, record);
		count += ret;
		i++;
	}
	if (count != 0)
		return (TRUE);
	return (FALSE);
} */

bool	hit_anything(t_scene *scene, t_ray ray, t_hit *record)
{
	if (find_hit_object(scene, ray, record) != NULL)
		return (TRUE);
	return (FALSE);
}

void	copy_hit_record(t_hit *origin, t_hit *dest)
{
	if (origin == NULL || dest == NULL)
		return ;
	dest->full = origin->full;
	dest->normal = origin->normal;
	dest->point = origin->point;
	dest->t = origin->t;
	dest->front_face = origin->front_face;
}

bool	hit_acceptable_range(double_t t)
{
	if (t <= 0)
		return (FALSE);
	else
		return (TRUE);
}
