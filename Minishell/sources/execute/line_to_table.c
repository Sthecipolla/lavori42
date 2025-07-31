/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:02:24 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 12:13:48 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

static int	ft_create_single_table(t_shell *shell, t_cmd_line **line, int *i);
static int	ft_set_cmd_table(t_shell *s, t_cmd_table *table, t_cmd_line **line);
static int	ft_if_redir(t_cmd_table *table, t_cmd_line **line);
static int	ft_if_heredoc(t_shell *s, t_cmd_table *table, t_cmd_line **line);

void	ft_line_to_table(t_shell *shell)
{
	t_cmd_line	*line;
	int			i;

	reorder_cmd_line(shell, shell->cmd_line);
	line = shell->cmd_line;
	shell->cmd_tables = NULL;
	ft_set_environment(shell);
	i = 0;
	while (line != NULL)
	{
		if (line->flag == PIPE)
			line = line->next;
		while (line != NULL && line->flag != PIPE)
		{
			if (ft_create_single_table(shell, &line, &i) != ERR_SUCCESS)
				return ;
			i++;
		}
	}
	shell->cmds_nmb = ft_lstsize(shell->cmd_tables);
}

static int	ft_create_single_table(t_shell *shell, t_cmd_line **line, int *i)
{
	t_cmd_table	*table_tmp;
	t_list		*new_node;
	int			cmd_table_ret;

	table_tmp = (t_cmd_table *) ft_calloc(1, sizeof(t_cmd_table));
	if (table_tmp == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
	ft_init_cmd_table(table_tmp, *i);
	cmd_table_ret = ft_set_cmd_table(shell, table_tmp, line);
	if (cmd_table_ret == ERROR)
		ft_fast_forward_to_next_pipe(line);
	else if (cmd_table_ret == HEREDOC_SIGINT)
		return (ft_return_to_prompt(shell), HEREDOC_SIGINT);
	new_node = ft_lstnew(table_tmp);
	if (new_node == NULL)
		return (ft_free_cmd_table(table_tmp), \
			ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
	if (shell->cmd_tables == NULL)
		shell->cmd_tables = new_node;
	else
		ft_lstadd_back(&(shell->cmd_tables), new_node);
	return (ERR_SUCCESS);
}

static int	ft_set_cmd_table(t_shell *s, t_cmd_table *table, t_cmd_line **line)
{
	int	ret;

	while ((*line) != NULL && (*line)->flag != PIPE)
	{
		ret = ft_if_redir(table, line);
		if (ret == ERROR)
			return (ERROR);
		ret = ft_if_heredoc(s, table, line);
		if (ret == ERROR || ret == HEREDOC_SIGINT)
			return (ret);
		if ((*line) != NULL && ((*line)->flag == COMMAND \
				|| (*line)->flag == EMPTY))
			ft_set_command(s, table, line);
	}
	return (EXIT_SUCCESS);
}

static int	ft_if_redir(t_cmd_table *table, t_cmd_line **line)
{
	int	flag;

	flag = 0;
	if ((*line) != NULL && (*line)->flag == REDIR_IN)
	{
		flag = 1;
		if (ft_set_input_fd(table, line) == -1)
			return (ft_set_cmd_to_null(table), ERROR);
	}
	else if ((*line) != NULL && (*line)->flag == REDIR_OUT)
	{
		flag = 1;
		if (ft_set_output_fd(table, line) == -1)
			return (ft_set_cmd_to_null(table), ERROR);
	}
	else if ((*line) != NULL && (*line)->flag == RED_APPEND)
	{
		flag = 1;
		if (ft_set_append_fd(table, line) == -1)
			return (ft_set_cmd_to_null(table), ERROR);
	}
	return (flag);
}

static int	ft_if_heredoc(t_shell *s, t_cmd_table *table, t_cmd_line **line)
{
	int	heredoc_return;
	int	flag;

	flag = 0;
	if ((*line) != NULL && ((*line)->flag == HERE_DOC || \
		(*line)->flag == HERE_DOC_NE))
	{
		flag = 1;
		heredoc_return = ft_set_heredoc_fd(s, table, line);
		if (heredoc_return == -1)
			return (ft_set_cmd_to_null(table), ERROR);
		else if (heredoc_return == HEREDOC_SIGINT)
			return (HEREDOC_SIGINT);
	}
	return (flag);
}
