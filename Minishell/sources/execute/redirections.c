/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 11:58:41 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/19 15:25:15 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

int	ft_set_input_fd(t_cmd_table *table, t_cmd_line **line)
{
	(*line) = (*line)->next;
	if (*line == NULL)
		return (-1);
	if (table->infd != STDIN_FILENO)
		close(table->infd);
	if ((*line)->flag == AMBIGUOUS || access((*line)->str, R_OK) == -1)
	{
		if ((*line)->flag == AMBIGUOUS)
			errno = EAMBRED;
		table->infd = -1;
		ft_print_error(PROG_NAME, (*line)->str);
		return (-1);
	}
	table->infd = open((*line)->str, O_RDONLY);
	if (table->infd == -1)
		ft_print_error(PROG_NAME, (*line)->str);
	(*line) = (*line)->next;
	return (table->infd);
}

int	ft_set_output_fd(t_cmd_table *table, t_cmd_line **line)
{
	(*line) = (*line)->next;
	if (*line == NULL)
		return (-1);
	if (table->outfd != STDOUT_FILENO)
		close(table->outfd);
	if ((*line)->flag == AMBIGUOUS || *((*line)->str) == '\0')
	{
		if ((*line)->flag == AMBIGUOUS)
			errno = EAMBRED;
		else
			errno = ENOENT;
		table->outfd = -1;
		ft_print_error(PROG_NAME, (*line)->str);
		return (-1);
	}
	table->outfd = open((*line)->str, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (table->outfd == -1)
		ft_print_error(PROG_NAME, (*line)->str);
	(*line) = (*line)->next;
	return (table->outfd);
}

int	ft_set_append_fd(t_cmd_table *table, t_cmd_line **line)
{
	(*line) = (*line)->next;
	if (*line == NULL)
		return (-1);
	if (table->outfd != STDOUT_FILENO)
		close(table->outfd);
	if ((*line)->flag == AMBIGUOUS || *((*line)->str) == '\0')
	{
		if ((*line)->flag == AMBIGUOUS)
			errno = EAMBRED;
		else
			errno = ENOENT;
		table->outfd = -1;
		ft_print_error(PROG_NAME, (*line)->str);
		return (-1);
	}
	table->outfd = open((*line)->str, O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (table->outfd == -1)
		ft_print_error(PROG_NAME, (*line)->str);
	(*line) = (*line)->next;
	return (table->outfd);
}
