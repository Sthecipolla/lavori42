/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:07:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:46:57 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

// altro numero nessuna
// 1 free la prima
// 2 free la seconda
// 3 free entrambe

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

int	check_quotes(char *str)
{
	int		i;
	char	type_of_quotes;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			type_of_quotes = str[i];
			i++;
			while (str[i] != type_of_quotes && str[i] != '\0')
				i++;
			if (str[i] == '\0')
				return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

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
