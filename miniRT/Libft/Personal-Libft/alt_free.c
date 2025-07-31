/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:29:40 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 13:56:49 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "personal_libft.h"

/*
PARAMETERS
matrix:	the 2d char matrix to be freed

DESCRIPTION
This function frees the memory allocated for a two dimensional matrix of
characters.

RETURN VALUE
None.
*/
void	free_char_matrix2(void *p)
{
	size_t	i;
	char	**matrix;

	if (p == NULL)
		return ;
	matrix = (char **) p;
	i = 0;
	while (matrix[i] != NULL)
		free(matrix[i++]);
	free(matrix);
}

/*
PARAMETERS
matrix:	the 3d char matrix to be freed

DESCRIPTION
This function frees the memory allocated for a three dimensional matrix of
characters.

RETURN VALUE
None.
*/
void	free_char_matrix3(void *p)
{
	size_t	i;
	size_t	j;
	char	***matrix;

	if (p == NULL)
		return ;
	matrix = (char ***) p;
	i = 0;
	while (matrix[i] != NULL)
	{
		j = 0;
		while (matrix[i][j] != NULL)
			free(matrix[i][j++]);
		free(matrix[i++]);
	}
	free(matrix);
}
