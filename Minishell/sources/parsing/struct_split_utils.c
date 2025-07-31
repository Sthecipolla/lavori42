/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_split_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:06:33 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:07:17 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

void	*ft_add_node(t_cmd_line **base, char *string, int flag)
{
	t_cmd_line	*tmp;

	if (string == NULL)
		return (NULL);
	if (*base == NULL)
	{
		*base = malloc(sizeof(t_cmd_line));
		if (*base == NULL)
			return (NULL);
		(*base)->str = string;
		(*base)->flag = flag;
		(*base)->next = NULL;
		return ("");
	}
	tmp = *base;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = malloc(sizeof(t_cmd_line));
	if (tmp->next == NULL)
		return (NULL);
	tmp = tmp->next;
	tmp->flag = flag;
	tmp->str = string;
	tmp->next = NULL;
	return ("");
}

char	*quotes(char *str, int *i, t_shell *t, char c)
{
	char	*quotes;
	char	*app;

	(*i)++;
	quotes = (char *)ft_calloc(1, sizeof(char));
	if (quotes == NULL)
		return (NULL);
	while (str[*i] != c && str[*i] != '\0')
	{
		if (ft_add_char(&quotes, str[*i]) == NULL)
			return (free(quotes), NULL);
		(*i)++;
	}
	if (last_node_h(t->cmd_line, TRUE) == TRUE)
		return ((*i)++, quotes);
	if (c == '"')
	{
		app = quotes;
		quotes = expand_variable(quotes, t);
		free(app);
	}
	(*i)++;
	return (quotes);
}

static int	ambig_red(char *str, int i, char *app, t_cmd_line *arg)
{
	if (app[0] != '\0')
		return (FALSE);
	while (i > 0 && ft_isspace(str[i]) == TRUE)
		i--;
	if ((str[i] != '<' || str[i] != '>') && last_node_re(arg) == TRUE)
		return (TRUE);
	return (FALSE);
}

void	*ft_space(char *str, int *i, char **app, t_cmd_line **arg)
{
	char	*check;
	int		flag;

	flag = ARG;
	if (ambig_red(str, *i, *app, *arg) == TRUE)
		flag = AMBIGUOUS;
	if (flag == AMBIGUOUS)
		*app = ft_safe_strjoin(*app, cmd_add_error(str, *i), 3);
	if (*app == NULL)
		return (free(*app), free_struct_cmd(arg), NULL);
	if (ft_strlen(*app) == 0)
		flag = EMPTY;
	if (only_one(*arg, str, *i, EMPTY) == TRUE || flag == ARG
		|| flag == AMBIGUOUS)
	{
		check = ft_add_node(arg, *app, flag);
		*app = (char *)ft_calloc(1, sizeof(char));
		if (check == NULL || *app == NULL)
			return (free(*app), free_struct_cmd(arg), NULL);
	}
	while (ft_isspace(str[*i]) == TRUE)
		(*i)++;
	return ("");
}

int	all_same(char c, char *app)
{
	int	i;

	i = 0;
	while (app[i] == c && app[i] != '\0')
		i++;
	if (app[i] == '\0')
		return (1);
	return (0);
}
