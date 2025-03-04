/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mshahein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:47:00 by mshahein          #+#    #+#             */
/*   Updated: 2025/03/03 11:05:00 by mshahein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	while (len > 0)
	{
		if (filename[len] == '.')
		{
			if (filename[len + 1] == 'f' && filename[len + 2] == 'd'
				&& filename[len + 3] == 'f' && filename[len + 4] == '\0')
			{
				return ;
			}
			else
			{
				perror("Error: estensione del file non valida\n");
				exit(EXIT_FAILURE);
			}
		}
		len--;
	}
	perror("Error: estensione del file non valida\n");
	exit(EXIT_FAILURE);
}

int	ft_safe_fd(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error nell'apertura del file");
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	ft_check_nbr_col(char *filename)
{
	int		fd;
	char	*line;
	int		first_line;

	fd = ft_safe_fd(filename);
	line = get_next_line(fd);
	first_line = ft_count_words(line, ' ');
	while (line)
	{
		if (first_line != ft_count_words(line, ' '))
		{
			while (line)
			{
				free(line);
				line = get_next_line(fd);
			}
			perror("Error: numero di colonne diverso\n");
			exit(EXIT_FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

int	mat_len(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
		i++;
	return (i);
}

void	free_int_matrix(int **mat)
{
	int	i;

	i = 0;
	while (mat[i])
	{
		free(mat[i]);
		i++;
	}
	free(mat);
}
