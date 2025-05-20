/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:06:40 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/19 17:24:15 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

static int	special(int flag)
{
	if (flag == HERE_DOC || flag == RED_APPEND)
		return (1);
	if (flag == REDIR_IN || flag == REDIR_OUT)
		return (1);
	if (flag == HERE_DOC_NE)
		return (1);
	return (0);
}

static void	man(t_cmd_line *app)
{
	if (app == NULL)
		return ;
	if (app->flag == PIPE || special(app->flag) == 1 || app->flag == ERROR)
		return ;
	app->flag = COMMAND;
}

int	set_flag(t_cmd_line *line)
{
	int	prev_flag;

	if (line == NULL)
		return (1);
	if (line->flag == ARG)
		line->flag = COMMAND;
	prev_flag = 2000;
	while (line != NULL)
	{
		if (special(line->flag) == 1 && line->next != NULL)
			man(line->next->next);
		if ((special(prev_flag) == 1 || prev_flag == PIPE)
			&& line->flag == PIPE)
			line->flag = ERROR;
		if (line->flag == ARG && prev_flag == PIPE)
		{
			line->flag = COMMAND;
		}
		prev_flag = line->flag;
		line = line->next;
	}
	return (1);
}

void	here_doc(int len, t_shell *trash)
{
	int			i;
	char		**limiters;
	int			element;
	t_cmd_line	*cmd;

	cmd = trash->cmd_line;
	element = 0;
	limiters = (char **)malloc((count_here_doc(cmd, len) + 1) * sizeof(char *));
	i = -1;
	while (len > ++i && cmd != NULL)
	{
		if ((cmd->flag == HERE_DOC || cmd->flag == HERE_DOC_NE) && i + 1 < len)
		{
			limiters[element] = cmd->next->str;
			element++;
		}
		cmd = cmd->next;
	}
	limiters[element] = NULL;
	ft_here_doc(limiters, trash);
}

int	parsing(t_shell *trash)
{
	int	error;

	if (check_quotes(trash->str) == FALSE)
	{
		ft_dprintf(STDERR_FILENO, "%s: Unclosed quotes\n", PROG_NAME);
		return (trash->exit_status = ERR_SYNTAX, FALSE);
	}
	if (ft_split_struct(trash->str, 0, trash) == NULL)
		return (ft_clean(trash, 1), 0);
	set_flag(trash->cmd_line);
	if (start_checks(trash, &error) == 1)
	{
		here_doc(error, trash);
		return (free_struct_cmd(&trash->cmd_line), FALSE);
	}
	return (TRUE);
}
