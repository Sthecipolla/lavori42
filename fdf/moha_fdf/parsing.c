/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:46:48 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/01 18:43:00 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	*fun(char **tmp, int size)
{
	int		i;
	int		*res;

	res = malloc(sizeof(int) * size);
	i = 0;
	while (tmp[i])
	{
		res[i] = ft_atoi(tmp[i]);
		i++;
	}
	return (res);
}

void	*ft_realloc(void *ptr, size_t size_old, size_t size_new)
{
	void	*new_data;

	new_data = NULL;
	if (size_new)
	{
		if (!ptr)
			return (ft_calloc(1, size_new));
		new_data = ft_calloc(1, size_new);
		if (new_data)
		{
			ft_memcpy(new_data, ptr, size_old);
			free(ptr);
		}
	}
	return (new_data);
}

void	parsing(t_mat *mat, char *filename)
{
	int		fd;
	char	*s;
	int		i;
	char	**tmp;

	i = 0;
	check_name(filename);
	ft_check_nbr_col(filename);
	fd = ft_safe_fd(filename);
	mat->mat = ft_calloc(sizeof(int *), 1);
	s = get_next_line(fd);
	while (s != NULL)
	{
		mat->mat = ft_realloc(mat->mat, sizeof (int *) * (i),
				sizeof (int *) * (i + 2));
		tmp = ft_split(s, ' ');
		mat->x = mat_len(tmp);
		mat->mat[i] = fun(tmp, mat->x);
		free(s);
		free_char_matrix(tmp);
		i++;
		s = get_next_line(fd);
	}
	mat->mat[i] = NULL;
	close(fd);
}
