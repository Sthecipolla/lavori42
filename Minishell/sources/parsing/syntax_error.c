/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:24:38 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 12:39:27 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

static int	special(int en)
{
	if (en == PIPE || en == HERE_DOC)
		return (1);
	if (en == REDIR_IN || en == REDIR_OUT)
		return (1);
	if (en == RED_APPEND)
		return (1);
	return (0);
}

int	check_error_flag(t_cmd_line *cmd, int *str)
{
	int	i;

	i = 0;
	if ((special(cmd->flag) == 1 && cmd->next == NULL) || cmd->flag == PIPE)
	{
		ft_dprintf(STDERR_FILENO, "minishell: Syntax error\n");
		return (*str = i, 1);
	}
	while (cmd != NULL)
	{
		*str = i;
		if (cmd->flag == ERROR)
		{
			ft_dprintf(STDERR_FILENO, "minishell: Syntax error\n");
			return (1);
		}
		if (special(cmd->flag) == 1 && cmd->next == NULL)
		{
			ft_dprintf(STDERR_FILENO, "minishell: Syntax error\n");
			return (1);
		}
		i++;
		cmd = cmd->next;
	}
	return (0);
}

int	check_sintax(t_shell *trash, int *str)
{
	if (check_error_flag(trash->cmd_line, str) == 1)
		return (1);
	return (0);
}

int	start_checks(t_shell *trash, int *str)
{
	if (trash->cmd_line == NULL)
		return (0);
	if (check_sintax(trash, str) == 1)
	{
		trash->exit_status = ERR_SYNTAX;
		return (1);
	}
	return (0);
}
