/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:26:40 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	copy_light(t_scene original, t_scene *copy)
{
	unsigned int	i;

	i = 0;
	copy->lights = (t_light *) malloc(sizeof(t_light) * original.num_lights);
	if (copy->lights == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	while (i < original.num_lights)
	{
		copy->lights[i].color = original.lights[i].color;
		copy->lights[i].def_color = original.lights[i].def_color;
		copy->lights[i].point = original.lights[i].point;
		copy->lights[i].ratio = original.lights[i].ratio;
		i++;
	}
	copy->num_lights = original.num_lights;
	return (SUCCESS);
}

static int	copy_ambient_light(t_scene original, t_scene *copy)
{
	copy->ambient = (t_ambient *) malloc(sizeof(t_ambient));
	if (copy->ambient == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	copy->ambient->color = original.ambient->color;
	copy->ambient->ratio = original.ambient->ratio;
	copy->ambient->def_color = original.ambient->def_color;
	return (SUCCESS);
}

static int	copy_camera(t_scene original, t_scene *copy)
{
	copy->camera = (t_camera *) malloc(sizeof(t_camera));
	if (copy->ambient == NULL)
		return (ft_malloc_error(NULL, NULL), FAIL);
	copy->camera->dir = original.camera->dir;
	copy->camera->fov = original.camera->fov;
	copy->camera->point = original.camera->point;
	return (SUCCESS);
}

static void	set_all_nill(t_scene *copy)
{
	copy->ambient = NULL;
	copy->camera = NULL;
	copy->lights = NULL;
	copy->num_lights = 0;
	copy->objects = NULL;
	copy->num_objects = 0;
}

t_scene	*ft_copy_scene(t_scene *scene)
{
	t_scene	*copy;

	if (!scene)
		return (NULL);
	copy = (t_scene *) malloc(sizeof(t_scene));
	if (!copy)
		return (NULL);
	set_all_nill(copy);
	copy->num_lights = scene->num_lights;
	if (copy_light(*scene, copy) != SUCCESS)
		return (NULL);
	if (copy_ambient_light(*scene, copy) != SUCCESS)
		return (NULL);
	if (copy_camera(*scene, copy) != SUCCESS)
		return (NULL);
	if (copy_objs(*scene, copy) != SUCCESS)
		return (NULL);
	return (copy);
}
