/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:01 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/22 12:47:01 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static void	set_all_nill(t_scene *scene);

static int	check_file_valid(char *file, t_data *data)
{
	char	*str;
	int		fd;
	char	str2[3];

	if (!file)
		return (data->errnmb = EINVALF, ft_err_pri(PROG_NAME, file, data, 0));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (data->errnmb = EINVALF, ft_err_pri(PROG_NAME, file, data, 0));
	str = ft_strrchr(file, '.');
	if (!str)
		return (data->errnmb = EINVALF, close(fd), \
			ft_err_pri(PROG_NAME, file, data, 0));
	else if (str[1] != 'r' || str[2] != 't' || str[3] != '\0')
		return (data->errnmb = EINVALF, close(fd), \
			ft_err_pri(PROG_NAME, file, data, 0));
	if (read(fd, str2, 1) <= 0)
	{
		data->errnmb = EEMPTYF;
		return (close(fd), ft_err_pri(PROG_NAME, file, data, 0));
	}
	close(fd);
	return (SUCCESS);
}

int	check_num_args(int argc, t_data *data)
{
	if (argc < 2)
		data->errnmb = E2SMALL;
	else if (argc > 2)
		data->errnmb = E2BIG;
	if (data->errnmb != SUCCESS)
		ft_print_error(PROG_NAME, NULL, data->errnmb);
	return (data->errnmb);
}

int	parse_scene(int argc, char **argv, t_data *data)
{
	data->scene = malloc(sizeof(t_scene));
	if (data->scene == NULL)
		return (data->errnmb = errno, ft_malloc_error(NULL, NULL), errno);
	set_all_nill(data->scene);
	if (check_num_args(argc, data) != SUCCESS)
		return (data->errnmb);
	if (check_file_valid(argv[1], data) != SUCCESS)
		return (data->errnmb);
	if (check_file(argv[1], data) != SUCCESS)
		return (data->errnmb);
	if (data->scene->ambient == NULL)
		return (data->errnmb = ENOAMB, ft_err_pri(PROG_NAME, argv[1], data, 0));
	else if (data->scene->lights == NULL)
		return (data->errnmb = ENOLIT, ft_err_pri(PROG_NAME, argv[1], data, 0));
	else if (data->scene->camera == NULL)
		return (data->errnmb = ENOCAM, ft_err_pri(PROG_NAME, argv[1], data, 0));
	return (SUCCESS);
}

static void	set_all_nill(t_scene *scene)
{
	if (scene == NULL)
		return ;
	scene->num_lights = 0;
	scene->ambient = NULL;
	scene->lights = NULL;
	scene->camera = NULL;
	scene->objects = NULL;
	scene->num_objects = 0;
}
