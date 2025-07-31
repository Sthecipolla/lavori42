/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:26 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 22:11:15 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	fill_cordinate(t_data *data, t_sphere *sphere, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num_sign(matrix[i], TRUE) == FALSE
			|| ft_is_double(matrix[i]) == FALSE)
		{
			data->errnmb = ECENTER;
		}
		i++;
	}
	if (i != 3)
		data->errnmb = ECENTER;
	if (data->errnmb == ECENTER)
	{
		return (free_matrix(matrix));
	}
	sphere->center.x = ft_atof(matrix[0]);
	sphere->center.y = ft_atof(matrix[1]);
	sphere->center.z = ft_atof(matrix[2]);
	free_matrix(matrix);
}

static void	fill_dia(t_data *data, char *value, t_sphere *sphere)
{
	if (ft_is_num_sign(value, TRUE) == FALSE || ft_is_double(value) == FALSE)
	{
		data->errnmb = EDIAMET;
		return ;
	}
	if (ft_atof(value) <= 0)
	{
		data->errnmb = EDIAMET;
		return ;
	}
	sphere->diameter = ft_atof(value);
}

static int	fill_color(t_data *data, t_sphere *sphere, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num(matrix[i], FALSE) == FALSE)
			data->errnmb = ECOLORS;
		i++;
	}
	if (i != 3)
		data->errnmb = ECOLORS;
	if (data->errnmb == ECOLORS)
		return (FALSE);
	if (atol(matrix[0]) < 0 || atol(matrix[0]) > 255)
		return (FALSE);
	sphere->color.red = (int)atol(matrix[0]);
	if (atol(matrix[1]) < 0 || atol(matrix[1]) > 255)
		return (FALSE);
	sphere->color.green = (int)atol(matrix[1]);
	if (atol(matrix[2]) < 0 || atol(matrix[2]) > 255)
		return (FALSE);
	sphere->color.blue = (int)atol(matrix[2]);
	return (TRUE);
}

t_sphere	*sphere(char **coordinate, t_data *data)
{
	t_sphere	*sphere;
	char		**matrix;

	if (num_args(coordinate, 3) == FALSE)
		return (data->errnmb = ENUMARG, NULL);
	sphere = malloc(sizeof(t_sphere));
	if (sphere == NULL)
		return (data->errnmb = errno, NULL);
	matrix = ft_split(coordinate[0], ',');
	if (matrix == NULL)
		return (data->errnmb = errno, free(sphere), NULL);
	fill_cordinate(data, sphere, matrix);
	fill_dia(data, coordinate[1], sphere);
	if (data->errnmb != SUCCESS)
		return (free(sphere), NULL);
	matrix = ft_split(coordinate[2], ',');
	if (matrix == NULL)
		return (data->errnmb = errno, free(sphere), NULL);
	if (fill_color(data, sphere, matrix) == FALSE)
	{
		data->errnmb = ECOLORS;
		return (free_matrix(matrix), free(sphere), NULL);
	}
	free_matrix(matrix);
	return (sphere);
}
