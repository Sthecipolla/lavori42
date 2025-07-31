/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_expand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:24:28 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/12 16:24:31 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

static int	valid(char c)
{
	if (ft_isspace(c) == TRUE)
		return (TRUE);
	if (ft_isalpha(c) == TRUE || ft_isalnum(c) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	ch_hdc(char *new_str)
{
	int	i;

	i = ft_strlen(new_str) - 1;
	if (i < 0)
		return (FALSE);
	if (i - 1 < 0)
		return (FALSE);
	while (ft_isspace(new_str[i]) == TRUE || new_str[i] == '\''
		|| new_str[i] == '"')
	{
		if (i == 0)
			return (FALSE);
		i--;
	}
	if (i - 1 < 0)
		return (FALSE);
	if (new_str[i] == '<' && new_str[i - 1] == '<' && (i - 1 == 0
			|| valid(new_str[i - 2]) == TRUE))
		return (TRUE);
	return (FALSE);
}

static int	is_pair(char *str, int i)
{
	int	x;

	x = 0;
	while (str[i] == '$')
	{
		x++;
		i++;
	}
	return (x);
}

static int	have_quotes(char *str, int i)
{
	while (ft_isspace(str[i]) == FALSE && str[i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	just_write(char **new_str, char *str, int *i, t_shell *t)
{
	if (have_quotes(str, *i) == FALSE)
	{
		while (ft_isspace(str[*i]) == FALSE && str[*i] != '\0')
		{
			if (ft_add_char(new_str, str[*i]) == NULL)
				return (free(*new_str), ft_clean(t, 1));
			(*i)++;
		}
		return ;
	}
	if (is_pair(str, *i) % 2 == 1 && is_pair(str, *i) != FALSE)
		(*i)++;
	while (ft_isspace(str[*i]) == FALSE && str[*i] != '\0')
	{
		if (ft_add_char(new_str, str[*i]) == NULL)
			return (free(*new_str), ft_clean(t, 1));
		(*i)++;
	}
}
