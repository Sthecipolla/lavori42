/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_clean.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 14:00:28 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

void	free_camera(t_camera **camera)
{
	if (*camera == NULL)
		return ;
	free(*camera);
	*camera = NULL;
}

void	free_ambient(t_ambient **ambient)
{
	if (*ambient == NULL)
		return ;
	free(*ambient);
	*ambient = NULL;
}

void	free_lights(t_light **lights)
{
	if (*lights == NULL)
		return ;
	free(*lights);
	*lights = NULL;
}

void	free_objects(t_object *object, unsigned int num)
{
	unsigned int	i;

	if (object == NULL)
		return ;
	i = 0;
	while (i < num)
	{
		if (object[i].type == SPHERE)
			free(object[i].object->sphere);
		if (object[i].type == CYLINDER)
			free(object[i].object->cylinder);
		if (object[i].type == PLANE)
			free(object[i].object->plane);
		free(object[i].object);
		i++;
	}
	free(object);
}
