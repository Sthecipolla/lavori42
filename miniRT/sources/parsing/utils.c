/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:06:30 by daromoli          #+#    #+#             */
/*   Updated: 2025/07/21 16:06:30 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <miniRT.h>

// altro numero nessuna
// 1 free la prima
// 2 free la seconda
// 3 free entrambe

char	*ft_safe_strjoin(char *s, char *s2, int frees)
{
	char	*return_string;

	if (s != NULL && s2 != NULL)
		return_string = ft_strjoin(s, s2);
	else
		return_string = NULL;
	if (frees == 1 || frees == 3)
		free(s);
	if (frees == 2 || frees == 3)
		free(s2);
	return (return_string);
}

int	skip_space(char *str, int i)
{
	while (ft_isspace(str[i]) == TRUE)
		i++;
	return (i);
}

char	*ft_add_char(char **str, char c)
{
	char	app[2];

	app[1] = '\0';
	app[0] = c;
	*str = ft_safe_strjoin(*str, app, 1);
	if (*str == NULL)
		return (NULL);
	return ("");
}

/*
PARAMETERS
matrix: double pointer to char array (char**)

DESCRIPTION
This function frees a matrix (array of strings) 
allocated with functions like ft_split.

RETURN VALUE
None.
*/

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
	free(matrix);
}

/*
Removes newline character (\n) from the end of a string
Modifies the string in place
return pointer to the modified string
*/
char	*remove_newline(char *str)
{
	int	len;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	return (str);
}
