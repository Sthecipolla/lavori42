/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_obj.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 16:05:32 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static t_object	*create_object(t_data *data)
{
	t_object		*object;
	unsigned int	i;

	i = 0;
	object = malloc(sizeof(t_object) * (data->scene->num_objects + 1));
	if (object == NULL)
	{
		data->errnmb = errno;
		return (NULL);
	}
	while (data->scene->num_objects > i)
	{
		object[i] = data->scene->objects[i];
		i++;
	}
	free(data->scene->objects);
	return (object);
}

static int	add_obj(void *obj, t_data *data, int type, unsigned int pos)
{
	data->scene->objects[pos].object = malloc(sizeof(t_obj_union));
	if (type == SPHERE)
	{
		data->scene->objects[pos].object->sphere = obj;
		data->scene->objects[pos].def_color = \
			data->scene->objects[pos].object->sphere->color;
	}
	else if (type == CYLINDER)
	{
		data->scene->objects[pos].object->cylinder = obj;
		data->scene->objects[pos].def_color = \
			data->scene->objects[pos].object->cylinder->color;
	}
	else if (type == PLANE)
	{
		data->scene->objects[pos].object->plane = obj;
		data->scene->objects[pos].def_color = \
			data->scene->objects[pos].object->plane->color;
	}
	else
		return (FALSE);
	data->scene->objects[pos].type = type;
	return (TRUE);
}

int	add_object(void *object, t_data *data, int typea)
{
	t_object	*tmp;

	if (object == NULL)
		return (data->errnmb);
	if (data->scene->objects == NULL)
	{
		data->scene->objects = malloc(sizeof(t_object));
		if (data->scene->objects == NULL)
		{
			data->errnmb = errno;
			return (ft_malloc_error(NULL, NULL), data->errnmb);
		}
		data->scene->num_objects++;
		add_obj(object, data, typea, 0);
		return (SUCCESS);
	}
	tmp = create_object(data);
	if (tmp == NULL)
		return (data->errnmb);
	data->scene->objects = tmp;
	add_obj(object, data, typea, data->scene->num_objects);
	data->scene->num_objects++;
	return (SUCCESS);
}
