/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_sec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:28:23 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:28:36 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

int	there_is_quotes(char *str, int i)
{
	while (str[i] != '\'' && str[i] != '\"')
	{
		if (ft_isspace(str[i]) == TRUE || str[i] == '\0')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

static char	*add_node_of_ex(char *n_st, t_shell *t, char **app, int *j)
{
	char	*tmp;
	int		i;

	i = 0;
	while (ft_isspace(n_st[*j + i]) == FALSE && n_st[*j + i] != '\0')
		i++;
	i += *j;
	tmp = ft_substr(n_st, *j, i - *j);
	*app = ft_safe_strjoin(*app, tmp, 3);
	if (*app == NULL)
		return (NULL);
	if (ft_add_node(&t->cmd_line, *app, ARG) == NULL)
	{
		free(*app);
		return (NULL);
	}
	*app = (char *)ft_calloc(1, sizeof(char));
	if (*app == NULL)
		return (NULL);
	while (ft_isspace(n_st[i]) == TRUE)
		i++;
	*j = i;
	return ("");
}

static char	*ft_exp_var(char *n_str, t_shell *t)
{
	char	*app;

	app = n_str;
	n_str = expand_variable(n_str, t);
	free(app);
	if (n_str == NULL)
		return (NULL);
	return (n_str);
}

char	*there_are_spaces(char *n_str, t_shell *t, char **app, int j)
{
	int		i;
	char	*tmp;

	i = 0;
	n_str = ft_exp_var(n_str, t);
	if (n_str == NULL)
		return (NULL);
	while (n_str[i] != '\0')
	{
		if (ft_isspace(n_str[i]) == TRUE)
		{
			if (add_node_of_ex(n_str, t, app, &j) == NULL)
				return (NULL);
			while (ft_isspace(n_str[i]) == TRUE)
				i++;
			continue ;
		}
		i++;
	}
	if (j == 0)
		return (n_str);
	if (n_str[j] == '\0')
		return (free(n_str), (char *)ft_calloc(1, sizeof(char)));
	tmp = ft_strdup(&n_str[j]);
	return (free(n_str), tmp);
}
