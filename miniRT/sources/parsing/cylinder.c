/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:46 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 22:10:28 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	fill_cordinate(t_data *data, t_cylinder *cylinder, char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		if (ft_is_num_sign(matrix[i], TRUE) == FALSE
			|| ft_is_double(matrix[i]) == FALSE)
			data->errnmb = ECENTER;
		i++;
	}
	if (i != 3)
		data->errnmb = ECENTER;
	if (data->errnmb == ECENTER)
		return (free_matrix(matrix));
	cylinder->center.x = ft_atof(matrix[0]);
	cylinder->center.y = ft_atof(matrix[1]);
	cylinder->center.z = ft_atof(matrix[2]);
	free_matrix(matrix);
}

static void	fill_val(t_data *data, char *value, char *va, t_cylinder *cylinder)
{
	if (ft_is_num_sign(value, TRUE) == FALSE || ft_is_double(value) == FALSE)
		data->errnmb = EDIAMET;
	if (data->errnmb == EDIAMET)
		return ;
	if (ft_atof(value) <= 0)
	{
		data->errnmb = EDIAMET;
		return ;
	}
	if (ft_is_num_sign(va, TRUE) == FALSE || ft_is_double(va) == FALSE)
		data->errnmb = EHEIGHT;
	if (data->errnmb == EHEIGHT)
		return ;
	if (ft_atof(va) <= 0)
	{
		data->errnmb = EHEIGHT;
		return ;
	}
	cylinder->diameter = ft_atof(value);
	cylinder->height = ft_atof(va);
}

static int	fill_color(t_data *data, t_cylinder *cylinder, char **matrix)
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
	cylinder->color.red = (int)atol(matrix[0]);
	if (atol(matrix[1]) < 0 || atol(matrix[1]) > 255)
		return (FALSE);
	cylinder->color.green = (int)atol(matrix[1]);
	if (atol(matrix[2]) < 0 || atol(matrix[2]) > 255)
		return (FALSE);
	cylinder->color.blue = (int)atol(matrix[2]);
	return (TRUE);
}

static void	fill_normal(t_data *data, char **value, t_cylinder *cylinder)
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
	cylinder->axis.x = ft_atof(value[0]);
	cylinder->axis.y = ft_atof(value[1]);
	cylinder->axis.z = ft_atof(value[2]);
	free_matrix(value);
}

t_cylinder	*cylinder(char **coordinate, t_data *data, char	**m, t_cylinder	*cy)
{
	if (num_args(coordinate, 5) == FALSE)
		return (data->errnmb = ENUMARG, NULL);
	cy = malloc(sizeof(t_cylinder));
	if (cy == NULL)
		return (data->errnmb = errno, NULL);
	m = ft_split(coordinate[0], ',');
	if (m == NULL)
		return (data->errnmb = errno, free(cy), NULL);
	fill_cordinate(data, cy, m);
	fill_val(data, coordinate[2], coordinate[3], cy);
	if (data->errnmb != SUCCESS)
		return (free(cy), NULL);
	m = ft_split(coordinate[1], ',');
	if (m == NULL)
		return (data->errnmb = errno, free(cy), NULL);
	fill_normal(data, m, cy);
	if (data->errnmb != SUCCESS)
		return (free(cy), NULL);
	m = ft_split(coordinate[4], ',');
	if (m == NULL)
		return (data->errnmb = errno, free(cy), NULL);
	if (fill_color(data, cy, m) == FALSE)
		return (data->errnmb = ECOLORS, free_matrix(m), free(cy), NULL);
	return (free_matrix(m), cy);
}
