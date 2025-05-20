/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 19:30:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 11:14:13 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

static void	child_execution(t_shell *shell, t_cmd_table *cmd_table);
static void	child_man_fds(t_shell *s, t_cmd_table *table, int *pipefd, int *fd);

/*
*/
void	ft_exec_child(t_shell *s, t_cmd_table *table, int *pipefd, int *fd)
{
	t_uchar	exit_code;

	close(pipefd[0]);
	if (table->path == NULL)
	{
		if (*fd != -1)
			close(*fd);
		exit_code = ERR_SUCCESS;
		if (table->infd == -1 || table->outfd == -1)
			exit_code = ERR_GENERAL;
		return (close(pipefd[1]), ft_cleanup(s), exit(exit_code));
	}
	child_man_fds(s, table, pipefd, fd);
	child_execution(s, table);
}

static void	child_man_fds(t_shell *s, t_cmd_table *table, int *pipefd, int *fd)
{
	if (table->cmd_nmb == 0)
		*fd = STDIN_FILENO;
	if (table->infd != STDIN_FILENO)
	{
		close(*fd);
		*fd = table->infd;
	}
	if (dup2(*fd, STDIN_FILENO) == -1)
		return (close(pipefd[1]), ft_print_error("dup2", NULL), \
			ft_cleanup(s), exit(errno));
	if (*fd != STDIN_FILENO)
		close (*fd);
	if (table->cmd_nmb == s->cmds_nmb - 1)
		*fd = STDOUT_FILENO;
	if (table->outfd != STDOUT_FILENO)
		*fd = table->outfd;
	else if (table->cmd_nmb != s->cmds_nmb - 1)
		*fd = pipefd[1];
	if (dup2(*fd, STDOUT_FILENO) == -1)
		return (close(pipefd[1]), ft_print_error("dup2", NULL), \
			ft_cleanup(s), exit(errno));
	close(pipefd[1]);
}

static void	child_execution(t_shell *shell, t_cmd_table *cmd_table)
{
	int	errsv;

	errsv = ERR_SUCCESS;
	if (cmd_table->builtin_flag == FALSE)
	{
		ft_lstiter(shell->cmd_tables, ft_close_fds_cmd_table);
		ft_reset_signals_to_default(shell);
		execve(cmd_table->path, cmd_table->args, shell->env_vars);
	}
	else
	{
		ft_avoid_sigpipe(shell);
		ft_recall_builtin(shell, cmd_table, CHILD);
	}
	if (cmd_table->cmd_noprint == FALSE)
		errsv = ft_print_cmd_error(cmd_table);
	ft_cleanup(shell);
	exit(errsv);
}
