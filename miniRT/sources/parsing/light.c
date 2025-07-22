/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:55 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 22:22:47 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	fill_ratio(t_data *data, t_light *light, char *value)
{
	if (ft_is_num_sign(value, TRUE) == FALSE || ft_is_double(value) == FALSE)
		data->errnmb = ERATIO;
	if (data->errnmb == ERATIO)
		return ;
	if (ft_atof(value) > 1 || ft_atof(value) < 0)
	{
		data->errnmb = ERATIO;
		return ;
	}
	light->ratio = ft_atof(value);
}

static void	fill_coordinate(t_data *data, t_light *light, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num_sign(matrix[i], TRUE) == FALSE || \
			ft_is_double(matrix[i]) == FALSE)
			data->errnmb = ECOORDI;
		i++;
	}
	if (i != 3)
		data->errnmb = ECOORDI;
	if (data->errnmb == ECOORDI)
		return (free_matrix(matrix));
	light->point.x = ft_atof(matrix[0]);
	light->point.y = ft_atof(matrix[1]);
	light->point.z = ft_atof(matrix[2]);
	free_matrix(matrix);
}

static int	fill_color(t_light *light, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num(matrix[i], FALSE) == FALSE)
			return (FALSE);
		i++;
	}
	if (i != 3)
		return (FALSE);
	if (atol(matrix[0]) < 0 || atol(matrix[0]) > 255)
		return (FALSE);
	light->color.red = (int)atol(matrix[0]);
	if (atol(matrix[1]) < 0 || atol(matrix[1]) > 255)
		return (FALSE);
	light->color.green = (int)atol(matrix[1]);
	if (atol(matrix[2]) < 0 || atol(matrix[2]) > 255)
		return (FALSE);
	light->color.blue = (int)atol(matrix[2]);
	return (TRUE);
}

t_light	*light(char **coordinate, t_data *data)
{
	t_light	*light;
	char	**matrix;

	if (num_args(coordinate, 3) == FALSE)
		return (data->errnmb = ENUMARG, NULL);
	light = malloc(sizeof(t_light));
	if (light == NULL)
		return (data->errnmb = errno, NULL);
	matrix = ft_split(coordinate[0], ',');
	if (matrix == NULL)
		return (data->errnmb = errno, free(light), NULL);
	fill_coordinate(data, light, matrix);
	if (data->errnmb != SUCCESS)
		return (free(light), NULL);
	matrix = ft_split(coordinate[2], ',');
	if (matrix == NULL)
		return (data->errnmb = ECOLORS, free(light), NULL);
	if (fill_color(light, matrix) == FALSE)
		return (data->errnmb = ECOLORS, free_matrix(matrix), free(light), NULL);
	free_matrix(matrix);
	fill_ratio(data, light, coordinate[1]);
	if (data->errnmb != SUCCESS)
		return (free(light), NULL);
	light->def_color = light->color;
	return (light);
}
