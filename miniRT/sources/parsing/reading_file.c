/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:20 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/22 13:00:00 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	check_format_app(char **matrix, t_data *data)
{
	if (ft_strncmp(matrix[0], "L", ft_strlen(matrix[0])) == 0)
	{
		data->scene->lights = add_light(light(&matrix[1], data), data);
		if (data->scene->lights == NULL)
			return (data->errnmb);
	}
	else if (ft_strncmp(matrix[0], "sp", ft_strlen(matrix[0])) == 0)
	{
		if (add_object(sphere(&matrix[1], data), data, SPHERE) != SUCCESS)
			return (data->errnmb);
	}
	else if (ft_strncmp(matrix[0], "pl", ft_strlen(matrix[0])) == 0)
	{
		if (add_object(plane(&matrix[1], data, NULL), data, PLANE) != SUCCESS)
			return (data->errnmb);
	}
	else if (ft_strncmp(matrix[0], "cy", ft_strlen(matrix[0])) == 0)
	{
		if (add_object(cylinder(&matrix[1], data, \
			NULL, NULL), data, CYLINDER) != SUCCESS)
			return (data->errnmb);
	}
	else
		data->errnmb = ENOTEXI;
	return (data->errnmb);
}

static int	check_format(char *line, t_data *data)
{
	char	**matrix;
	void	*tmp;

	matrix = ft_split_alt(line, " \t\r\v\f");
	if (matrix == NULL)
		return (errno);
	if (ft_strncmp(matrix[0], "A", ft_strlen(matrix[0])) == 0)
	{
		tmp = (void *) ambient_light(&matrix[1], data);
		if (tmp == NULL)
			return (free_ambient(&data->scene->ambient), \
				free_matrix(matrix), data->errnmb);
		data->scene->ambient = (t_ambient *) tmp;
	}
	else if (ft_strncmp(matrix[0], "C", ft_strlen(matrix[0])) == 0)
	{
		tmp = (void *) camera(&matrix[1], data);
		if (tmp == NULL)
			return (free_camera(&data->scene->camera), \
				free_matrix(matrix), data->errnmb);
		data->scene->camera = (t_camera *) tmp;
	}
	else
		check_format_app(matrix, data);
	return (free_matrix(matrix), data->errnmb);
}

static int	lav_line(char *line)
{
	int	j;

	if (line[0] == '#')
	{
		free(line);
		return (FALSE);
	}
	line = remove_newline(line);
	if (line == NULL)
		return (FALSE);
	j = 0;
	while (ft_isspace(line[j]) && line[j] != '\0')
		j++;
	if (line[j] == '\0')
	{
		free(line);
		return (FALSE);
	}
	return (TRUE);
}

static int	reading(char *nf, t_data *data, int *n_li, int fd)
{
	char	*line;

	fd = open(nf, O_RDONLY);
	if (fd < 0)
		return (data->errnmb = EINVALF, data->errnmb);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(*n_li)++;
		if (lav_line(line) == FALSE)
			continue ;
		if (check_format(line, data) != SUCCESS)
		{
			while (line != NULL)
			{
				free(line);
				line = get_next_line(fd);
			}
			return (close(fd), data->errnmb);
		}
		free(line);
	}
	return (close(fd), data->errnmb);
}

int	check_file(char *file, t_data *data)
{
	int	num_line;

	num_line = 0;
	data->scene->num_objects = 0;
	if (reading(file, data, &num_line, -1) != SUCCESS)
	{
		ft_err_pri(PROG_NAME, file, data, num_line);
		return (data->errnmb);
	}
	return (SUCCESS);
}
