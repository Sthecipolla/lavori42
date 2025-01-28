/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:19 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 11:53:30 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_pointer(char **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

int	ft_clean(t_map *s, int error)
{
	int	i;

	i = -1;
	if (s->imgarr[0].img)
	{
		while (s->imgarr[++i].img != NULL)
			mlx_destroy_image(s->session, s->imgarr[i].img);
	}
	if (s->window)
		mlx_destroy_window(s->session, s->window);
	if (s->session)
		mlx_destroy_display(s->session);
	free_double_pointer(s->map);
	free(s->session);
	free(s);
	if (error > 0)
		error = error_print(error);
	exit(error);
}

int	len_col(char **map)
{
	int	mxlen_col;

	mxlen_col = 0;
	while (map[mxlen_col] != NULL)
		mxlen_col++;
	return (mxlen_col);
}

char	**create_a_copy_map(char **map)
{
	int		rows;
	char	**new_map;

	rows = 0;
	while (map[rows] != NULL)
		rows++;
	new_map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!new_map)
	{
		free(new_map);
		return (NULL);
	}
	new_map[rows] = NULL;
	rows = 0;
	while (map[rows] != NULL)
	{
		new_map[rows] = ft_strdup(map[rows]);
		if (!new_map[rows])
		{
			free_double_pointer(new_map);
			return (NULL);
		}
		rows++;
	}
	return (new_map);
}
