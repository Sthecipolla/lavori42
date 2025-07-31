/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_expand.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:08:00 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:16:47 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

static char	*while_find_var(char *str, int *i, char **variable)
{
	if (ft_isdigit(str[*i]) == TRUE)
	{
		if (ft_add_char(variable, str[*i]) == NULL)
			return (free(*variable), NULL);
		(*i)++;
		return ("");
	}
	while (ft_isspace(str[*i]) == FALSE && str[*i] && vl_ch_en(str[*i]) == 1)
	{
		if (str[*i] == '\'' || str[*i] == '"')
			break ;
		if (str[*i] == '=' || ft_isspace(str[*i]) == TRUE || str[*i] == '\0')
			break ;
		if (ft_add_char(variable, str[*i]) == NULL)
			return (free(*variable), NULL);
		(*i)++;
	}
	return ("");
}

static char	*search(t_shell *trash, int *i, t_list *envp, char *str)
{
	char	*variable;
	int		len;

	if (str[*i + 1] == '?')
		return ((*i) += 2, status(trash->exit_status));
	if (str[*i + 1] == '$' || vl_ch_en(str[*i + 1]) == 0)
		return ("");
	variable = (char *)ft_calloc(1, sizeof(char));
	if (variable == NULL)
		return (NULL);
	(*i)++;
	if (while_find_var(str, i, &variable) == NULL)
		return (NULL);
	if (ft_add_char(&variable, '=') == NULL)
		return (free(variable), NULL);
	len = ft_strlen(variable);
	while (envp != NULL)
	{
		if (ft_strncmp(variable, (char *)envp->content, len) == 0)
			return (free(variable), (char *)envp->content + len);
		envp = envp->next;
	}
	return (free(variable), "\0");
}

static char	*man_check(char *str, int *i, char **new_str)
{
	if (str[*i] == '$' && (str[*i + 1] == '"' || str[*i + 1] == '\''))
		return ((*i)++, "");
	if (ft_add_char(new_str, str[*i]) == NULL)
		return (free(*new_str), NULL);
	(*i)++;
	return ("");
}

char	*expand_variable(char *str, t_shell *trash)
{
	char	*new_str;
	int		i;
	t_list	*envp;

	i = 0;
	envp = trash->envp;
	new_str = (char *)ft_calloc(1, sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '$' && (vl_ch_en(str[i + 1]) == 1 || str[i + 1] == '?'))
		{
			new_str = ft_safe_strjoin(new_str, search(trash, &i, envp, str), 1);
			if (new_str == NULL)
				return (NULL);
			continue ;
		}
		if (str[i] == '\0')
			break ;
		if (man_check(str, &i, &new_str) == NULL)
			return (NULL);
	}
	return (new_str);
}
