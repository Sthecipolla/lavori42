/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_sec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:16 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 18:18:43 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	copy_va(t_light *new, t_light *old, int pos, int ze)
{
	int	new_pos;

	if (ze == FALSE)
		new_pos = 0;
	else
		new_pos = pos;
	new[pos].color = old[new_pos].color;
	new[pos].def_color = old[new_pos].def_color;
	new[pos].point = old[new_pos].point;
	new[pos].ratio = old[new_pos].ratio;
}

t_light	*add_light(t_light *light, t_data *data)
{
	t_light			*tmp;
	unsigned int	i;

	i = 0;
	if (light == NULL)
		return (free_lights(&data->scene->lights), NULL);
	if (data->scene->lights == NULL)
		return (data->scene->num_lights++, light);
	tmp = malloc(sizeof(t_light) * ((data->scene->num_lights) + 1));
	if (tmp == NULL)
		return (data->errnmb = errno, ft_malloc_error(NULL, NULL), NULL);
	data->scene->num_lights++;
	while (data->scene->num_lights - 1 > i)
	{
		copy_va(tmp, data->scene->lights, i, TRUE);
		i++;
	}
	copy_va(tmp, light, i, FALSE);
	free(light);
	free_lights(&data->scene->lights);
	return (tmp);
}
