/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:05 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 22:11:01 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	fill_cordinate(t_data *data, t_plane *plane, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num_sign(matrix[i], TRUE) == FALSE
			|| ft_is_double(matrix[i]) == FALSE)
			data->errnmb = ECOORDI;
		i++;
	}
	if (i != 3)
		data->errnmb = ECOORDI;
	if (data->errnmb == ECOORDI)
		return (free_matrix(matrix));
	plane->point.x = ft_atof(matrix[0]);
	plane->point.y = ft_atof(matrix[1]);
	plane->point.z = ft_atof(matrix[2]);
	free_matrix(matrix);
}

int	check_value_norm_to_one(char **matrix, int skip)
{
	double_t	x;
	double_t	y;
	double_t	z;
	double_t	magnitude;

	if (skip != SUCCESS)
		return (FALSE);
	x = ft_atof(matrix[0]);
	y = ft_atof(matrix[1]);
	z = ft_atof(matrix[2]);
	magnitude = sqrt(x * x + y * y + z * z);
	if (magnitude >= 0.99 && magnitude <= 1.01)
		return (TRUE);
	return (FALSE);
}

static void	fill_normal(t_data *data, char **value, t_plane *plane)
{
	int	i;

	i = 0;
	while (value[i] != NULL)
	{
		if (ft_is_num_sign(value[i], TRUE) == FALSE
			|| ft_is_double(value[i]) == FALSE)
			data->errnmb = ENORMAL;
		i++;
	}
	if (i != 3)
		data->errnmb = ENORMAL;
	if (check_value_norm_to_one(value, data->errnmb) == FALSE)
		data->errnmb = ENORMAL;
	if (data->errnmb == ENORMAL)
		return (free_matrix(value));
	plane->normal.x = ft_atof(value[0]);
	plane->normal.y = ft_atof(value[1]);
	plane->normal.z = ft_atof(value[2]);
	free_matrix(value);
}

static int	fill_color(t_data *data, t_plane *plane, char **matrix)
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
	plane->color.red = (int)atol(matrix[0]);
	if (atol(matrix[1]) < 0 || atol(matrix[1]) > 255)
		return (FALSE);
	plane->color.green = (int)atol(matrix[1]);
	if (atol(matrix[2]) < 0 || atol(matrix[2]) > 255)
		return (FALSE);
	plane->color.blue = (int)atol(matrix[2]);
	return (TRUE);
}

t_plane	*plane(char **coordinate, t_data *data, char **matr)
{
	t_plane	*plane;

	if (num_args(coordinate, 3) == FALSE)
		return (data->errnmb = ENUMARG, NULL);
	plane = malloc(sizeof(t_plane));
	if (plane == NULL)
		return (data->errnmb = errno, NULL);
	matr = ft_split(coordinate[0], ',');
	if (matr == NULL)
		return (free(plane), data->errnmb = errno, NULL);
	fill_cordinate(data, plane, matr);
	if (data->errnmb != SUCCESS)
		return (free(plane), NULL);
	matr = ft_split(coordinate[1], ',');
	if (matr == NULL)
		return (free(plane), data->errnmb = errno, NULL);
	fill_normal(data, matr, plane);
	if (data->errnmb != SUCCESS)
		return (free(plane), NULL);
	matr = ft_split(coordinate[2], ',');
	if (matr == NULL)
		return (free(plane), data->errnmb = errno, NULL);
	if (fill_color(data, plane, matr) == FALSE)
		return (data->errnmb = ECOLORS, free_matrix(matr), free(plane), NULL);
	return (free_matrix(matr), plane);
}
