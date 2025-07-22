/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:34 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/22 12:38:46 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	fill_coordinate(t_data *data, t_camera *camera, char **matrix)
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
	camera->point.x = ft_atof(matrix[0]);
	camera->point.y = ft_atof(matrix[1]);
	camera->point.z = ft_atof(matrix[2]);
	free_matrix(matrix);
}

static int	check_value(char **matrix, int skip)
{
	double_t	x;
	double_t	y;
	double_t	z;
	double_t	magnitude;

	if (skip == ENORMAL)
		return (FALSE);
	x = ft_atof(matrix[0]);
	y = ft_atof(matrix[1]);
	z = ft_atof(matrix[2]);
	magnitude = sqrt(x * x + y * y + z * z);
	if (magnitude >= 0.99 && magnitude <= 1.01)
		return (TRUE);
	return (FALSE);
}

static void	fill_div(t_data *data, t_camera *camera, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num_sign(matrix[i], TRUE) == FALSE || \
			ft_is_double(matrix[i]) == FALSE)
		{
			data->errnmb = ENORMAL;
			return (free_matrix(matrix));
		}
		i++;
	}
	if (i != 3)
		data->errnmb = ENORMAL;
	if (check_value(matrix, data->errnmb) == FALSE)
		data->errnmb = ENORMAL;
	if (data->errnmb == ENORMAL)
		return (free_matrix(matrix));
	camera->dir.x = ft_atof(matrix[0]);
	camera->dir.y = ft_atof(matrix[1]);
	camera->dir.z = ft_atof(matrix[2]);
	free_matrix(matrix);
}

static void	fill_fov(t_data *data, t_camera *camera, char *value)
{
	if (ft_is_num_sign(value, TRUE) == FALSE || \
		ft_is_double(value) == FALSE)
	{
		data->errnmb = EFOV;
	}
	if (data->errnmb == EFOV)
		return ;
	camera->fov = ft_atof(value);
	if (camera->fov < 1 || camera->fov > 179)
		data->errnmb = EFOV;
}

t_camera	*camera(char **coordinate, t_data *data)
{
	t_camera	*camera;
	char		**matrix;

	if (num_args(coordinate, 3) == FALSE)
		return (data->errnmb = ENUMARG, NULL);
	else if (data->scene->camera != NULL)
		return (data->errnmb = EALRCAM, NULL);
	camera = malloc(sizeof(t_camera));
	if (camera == NULL)
		return (data->errnmb = errno, NULL);
	matrix = ft_split(coordinate[0], ',');
	if (matrix == NULL)
		return (data->errnmb = errno, free(camera), NULL);
	fill_coordinate(data, camera, matrix);
	matrix = ft_split(coordinate[1], ',');
	if (matrix == NULL)
		return (data->errnmb = errno, free(camera), NULL);
	fill_div(data, camera, matrix);
	fill_fov(data, camera, coordinate[2]);
	if (data->errnmb != SUCCESS)
		return (free(camera), NULL);
	return (camera);
}
