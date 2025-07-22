/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_scene_obj.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:26:36 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 16:27:40 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	copy_cylinder(t_scene *ori, t_scene *copy, int pos)
{
	copy->objects[pos].object = malloc(sizeof(t_obj_union));
	if (copy->objects[pos].object == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	copy->objects[pos].object->cylinder = malloc(sizeof(t_cylinder));
	if (copy->objects[pos].object->cylinder == NULL)
		return (ft_malloc_error(copy->objects[pos].object, free), FAIL);
	copy->objects[pos].object->cylinder->center = \
		ori->objects[pos].object->cylinder->center;
	copy->objects[pos].object->cylinder->axis = \
		ori->objects[pos].object->cylinder->axis;
	copy->objects[pos].object->cylinder->diameter = \
		ori->objects[pos].object->cylinder->diameter;
	copy->objects[pos].object->cylinder->height = \
		ori->objects[pos].object->cylinder->height;
	copy->objects[pos].object->cylinder->color = \
		ori->objects[pos].object->cylinder->color;
	copy->objects[pos].def_color = ori->objects[pos].def_color;
	copy->objects[pos].type = ori->objects[pos].type;
	return (SUCCESS);
}

static int	copy_sphere(t_scene *ori, t_scene *copy, int pos)
{
	copy->objects[pos].object = malloc(sizeof(t_obj_union));
	if (copy->objects[pos].object == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	copy->objects[pos].object->sphere = malloc(sizeof(t_sphere));
	if (copy->objects[pos].object->sphere == NULL)
		return (ft_malloc_error(copy->objects[pos].object, free), FAIL);
	copy->objects[pos].object->sphere->center = \
		ori->objects[pos].object->sphere->center;
	copy->objects[pos].object->sphere->diameter = \
		ori->objects[pos].object->sphere->diameter;
	copy->objects[pos].object->sphere->color = \
		ori->objects[pos].object->sphere->color;
	copy->objects[pos].def_color = ori->objects[pos].def_color;
	copy->objects[pos].type = ori->objects[pos].type;
	return (SUCCESS);
}

static int	copy_plane(t_scene *ori, t_scene *copy, int pos)
{
	copy->objects[pos].object = malloc(sizeof(t_obj_union));
	if (copy->objects[pos].object == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	copy->objects[pos].object->plane = malloc(sizeof(t_plane));
	if (copy->objects[pos].object->plane == NULL)
		return (ft_malloc_error(copy->objects[pos].object, free), FAIL);
	copy->objects[pos].object->plane->point = \
		ori->objects[pos].object->plane->point;
	copy->objects[pos].object->plane->normal = \
		ori->objects[pos].object->plane->normal;
	copy->objects[pos].object->plane->color = \
		ori->objects[pos].object->plane->color;
	copy->objects[pos].def_color = ori->objects[pos].def_color;
	copy->objects[pos].type = ori->objects[pos].type;
	return (SUCCESS);
}

static int	add_obj(t_scene *ori, t_scene *copy, int pos)
{
	if (ori->objects[pos].object == NULL)
		return (FAIL);
	if (ori->objects[pos].type == SPHERE)
	{
		if (copy_sphere(ori, copy, pos) != SUCCESS)
			return (FAIL);
	}
	else if (ori->objects[pos].type == CYLINDER)
	{
		if (copy_cylinder(ori, copy, pos) != SUCCESS)
			return (FAIL);
	}
	else if (ori->objects[pos].type == PLANE)
	{
		if (copy_plane(ori, copy, pos) != SUCCESS)
			return (FAIL);
	}
	return (SUCCESS);
}

int	copy_objs(t_scene og, t_scene *copy)
{
	unsigned int	i;

	i = 0;
	copy->objects = (t_object *) malloc(sizeof(t_object) * og.num_objects);
	if (copy->objects == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	while (i < og.num_objects)
	{
		if (add_obj(&og, copy, i) != SUCCESS)
			return (copy->num_objects = i, FAIL);
		i++;
	}
	copy->num_objects = i;
	return (SUCCESS);
}
