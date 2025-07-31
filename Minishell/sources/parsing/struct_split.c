/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:07:26 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:00:07 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

static void	*pipe_while(char *str, int *i, char **app, t_cmd_line **arg)
{
	int	inter;
	int	flag;

	inter = 0;
	while (str[*i] == '|')
	{
		ft_add_char(app, str[*i]);
		if (*app == NULL)
			return (free_struct_cmd(arg), NULL);
		(*i)++;
		inter++;
	}
	if (inter > 1)
		flag = ERROR;
	else
		flag = PIPE;
	if (ft_add_node(arg, *app, flag) == NULL)
		return (free(app), free_struct_cmd(arg), NULL);
	return ("");
}

static void	*redirect_while(char *str, int *i, char **app, t_cmd_line **arg)
{
	int		inter;
	int		flag;
	char	c;

	inter = 0;
	c = str[*i];
	while (str[*i] == '<' || str[*i] == '>')
	{
		ft_add_char(app, str[*i]);
		if (app == NULL)
			return (NULL);
		(*i)++;
		inter++;
	}
	if (inter > 2 || all_same(c, *app) == 0)
		flag = ERROR;
	else
		flag = calc_flag(*app, str, *i);
	if (ft_add_node(arg, *app, flag) == NULL)
		return (free(app), free_struct_cmd(arg), NULL);
	return ("");
}

static void	*special_operator(char **app, char *str, int *i, t_cmd_line **arg)
{
	if (*app[0] != '\0')
	{
		if (ft_add_node(arg, *app, ARG) == NULL)
			return (free(app), free_struct_cmd(arg), NULL);
		*app = (char *)ft_calloc(1, sizeof(char));
		if (*app == NULL)
			return (NULL);
	}
	if (str[*i] == '|')
	{
		if (pipe_while(str, i, app, arg) == NULL)
			return (NULL);
	}
	else
		redirect_while(str, i, app, arg);
	*app = (char *)ft_calloc(1, sizeof(char));
	if (*app == NULL)
		return (NULL);
	return ("");
}

char	*char_men(char *str, int *i, char **app, t_shell *t)
{
	if (str[*i] == '\'' || str[*i] == '\"')
	{
		*app = ft_safe_strjoin(*app, quotes(str, i, t, str[*i]), 3);
		if (*app == NULL)
			ft_clean(t, 1);
		if (*app[0] == '\0' && (ft_isspace(str[*i]) || str[*i] == '\0'))
			if (ft_add_node(&t->cmd_line, strdup(""), ARG) == NULL)
				return (free(*app), NULL);
	}
	if (str[*i] != '\'' && str[*i] != '\"' && str[*i] != '\0'
		&& ft_isspace(str[*i]) == FALSE)
		*app = ft_safe_strjoin(ft_strdup(*app), normal_str(t, str, i, *app), 3);
	if (*app == NULL)
		return (NULL);
	if (str[*i] == '<' || str[*i] == '>' || str[*i] == '|')
	{
		if (special_operator(app, str, i, &t->cmd_line) == NULL)
			return (free(*app), NULL);
		*i = skip_space(str, *i);
		return ("");
	}
	if (ft_isspace(str[*i]) == TRUE || str[*i] == '\0')
		if (ft_space(str, i, app, &t->cmd_line) == NULL)
			return (NULL);
	return ("");
}

char	*ft_split_struct(char *str, int i, t_shell *t)
{
	char	*app;

	i = skip_space(str, i);
	app = (char *)ft_calloc(1, sizeof(char));
	if (app == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		if (char_men(str, &i, &app, t) == NULL)
			return (NULL);
	}
	return (free(app), "");
}
