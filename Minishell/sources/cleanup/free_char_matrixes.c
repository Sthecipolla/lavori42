/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_char_matrixes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:26:58 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 16:36:07 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <cleanup/minishell_cleanup.h>

/*
PARAMETERS
p:	the 2d char matrix to be freed

DESCRIPTION
This function frees the memory allocated for a two dimensional matrix of
characters.

RETURN VALUE
None.
*/
void	ft_free_char_matrix2(void *p)
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
p:	the 3d char matrix to be freed

DESCRIPTION
This function frees the memory allocated for a three dimensional matrix of
characters.

RETURN VALUE
None.
*/
void	ft_free_char_matrix3(void *p)
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
