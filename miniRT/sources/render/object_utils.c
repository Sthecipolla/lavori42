/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:17:04 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 14:19:23 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_object	*single_obj(t_scene *scene, t_ray ray, t_hit *record, t_uint i);

/*
DESCRIPTION
Ottiene il colore di un oggetto in base al suo tipo.
Colore di default (bianco) in caso di errore
*/
t_color	get_object_color(t_object *object)
{
	if (object->type == SPHERE)
		return (object->object->sphere->color);
	else if (object->type == PLANE)
		return (object->object->plane->color);
	else if (object->type == CYLINDER)
		return (object->object->cylinder->color);
	return ((t_color){0, 255, 255, 255});
}

/*
DESCRIPTION
Trova l'oggetto che è stato colpito dal raggio.
Restituisce NULL se nessun oggetto è stato trovato.
*/
t_object	*find_hit_object(t_scene *scene, t_ray ray, t_hit *record)
{
	t_uint		i;
	t_hit		alt_record;
	t_object	*closest_object;
	t_object	*tmp_object;

	if (record == NULL)
		record = &alt_record;
	closest_object = NULL;
	record->full = FALSE;
	i = 0;
	while (i < scene->num_objects)
	{
		tmp_object = single_obj(scene, ray, record, i);
		if (tmp_object != NULL)
			closest_object = tmp_object;
		i++;
	}
	return (closest_object);
}

static t_object	*single_obj(t_scene *scene, t_ray ray, t_hit *record, t_uint i)
{
	t_object	*hit_object;
	t_hit		tmp_record;
	t_object	*obj;
	bool		ret;

	hit_object = NULL;
	tmp_record.full = FALSE;
	obj = &scene->objects[i];
	ret = FALSE;
	if (obj->type == SPHERE)
		ret = hit_sphere(obj->object->sphere->center, \
			0.5 * obj->object->sphere->diameter, ray, &tmp_record);
	else if (obj->type == PLANE)
		ret = hit_plane(obj->object->plane->point, \
			obj->object->plane->normal, ray, &tmp_record);
	else if (obj->type == CYLINDER)
		ret = hit_cylinder(obj->object->cylinder, ray, &tmp_record);
	if (ret == TRUE && (record->full == FALSE || tmp_record.t < record->t))
	{
		copy_hit_record(&tmp_record, record);
		hit_object = obj;
	}
	return (hit_object);
}
