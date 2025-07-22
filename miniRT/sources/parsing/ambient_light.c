/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:05:22 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 21:53:21 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

static int	fill_color(char **n, t_ambient *amb)
{
	int	i;

	i = 0;
	while (n[i])
	{
		if (ft_is_num(n[i], FALSE) == FALSE)
			return (FALSE);
		i++;
	}
	if (i != 3)
		return (FALSE);
	if (atol(n[0]) < 0 || atol(n[0]) > 255)
		return (FALSE);
	amb->color.red = (int)atol(n[0]);
	if (atol(n[1]) < 0 || atol(n[1]) > 255)
		return (FALSE);
	amb->color.green = (int)atol(n[1]);
	if (atol(n[2]) < 0 || atol(n[2]) > 255)
		return (FALSE);
	amb->color.blue = (int)atol(n[2]);
	return (TRUE);
}

static int	fill_ratio(char *num)
{
	if (ft_is_num(num, TRUE) == FALSE || ft_is_double(num) == FALSE)
		return (FALSE);
	if (ft_atof(num) > 1 || ft_atof(num) < 0)
		return (FALSE);
	return (TRUE);
}

t_ambient	*ambient_light(char **coordinate, t_data *data)
{
	t_ambient	*ambient;
	char		**color;

	if (num_args(coordinate, 2) == FALSE)
		return (data->errnmb = ENUMARG, NULL);
	else if (data->scene->ambient != NULL)
		return (data->errnmb = EALRAMB, NULL);
	ambient = malloc(sizeof(t_ambient));
	if (ambient == NULL)
		return (data->errnmb = errno, NULL);
	if (fill_ratio(coordinate[0]) == FALSE)
		return (data->errnmb = ERATIO, free(ambient), NULL);
	color = ft_split(coordinate[1], ',');
	if (color == NULL)
		return (data->errnmb = errno, free(ambient), NULL);
	if (fill_color(color, ambient) == FALSE)
	{
		data->errnmb = ECOLORS;
		free_matrix(color);
		free(ambient);
		return (NULL);
	}
	ambient->ratio = ft_atof(coordinate[0]);
	ambient->def_color = ambient->color;
	return (free_matrix(color), ambient);
}
