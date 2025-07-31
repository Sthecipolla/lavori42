/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_table_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:12:03 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 11:12:15 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

void	ft_init_cmd_table(t_cmd_table *table, int i)
{
	table->infd = STDIN_FILENO;
	table->outfd = STDOUT_FILENO;
	table->builtin_flag = FALSE;
	table->builtin_id = -1;
	table->path = NULL;
	table->args = NULL;
	table->cmd_nmb = i;
	table->heredoc_flag = FALSE;
	table->heredoc_filename = NULL;
	table->heredoc_exp = FALSE;
	table->cmd_noprint = FALSE;
}

void	ft_fast_forward_to_next_pipe(t_cmd_line **line)
{
	if (line == NULL)
		return ;
	while ((*line) != NULL && (*line)->flag != PIPE)
		(*line) = (*line)->next;
}

void	ft_set_cmd_to_null(t_cmd_table *table)
{
	if (table->path != NULL)
		free(table->path);
	ft_free_char_matrix2(table->args);
	table->path = NULL;
	table->args = NULL;
	table->builtin_flag = FALSE;
	table->builtin_id = -1;
}
