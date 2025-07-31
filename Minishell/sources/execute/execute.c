/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:20:51 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 12:31:41 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

static int	ft_wait_for_children(pid_t pid);
static int	ft_exec_1cmd(t_shell *shell, t_list *cmd, int *pipefd, int *fd);
static void	ft_exec_parent(t_shell *s, t_cmd_table *cmd, int *pipefd, int *fd);

/*
*/
int	ft_exec_allcmd(t_shell *shell)
{
	int		pipefd[2];
	pid_t	pid;
	int		fd;
	t_list	*cmds;

	cmds = shell->cmd_tables;
	pid = 0;
	fd = -1;
	if (shell->cmds_nmb == 1 && \
		((t_cmd_table *) cmds->content)->builtin_flag == TRUE)
		ft_recall_builtin(shell, (t_cmd_table *) cmds->content, PARENT);
	else
	{
		while (cmds != NULL)
		{
			pid = ft_exec_1cmd(shell, cmds, pipefd, &fd);
			cmds = cmds->next;
		}
		shell->exit_status = ft_wait_for_children(pid);
		def_signal(shell);
	}
	return (pid);
}

static int	ft_wait_for_children(pid_t pid)
{
	int		wstatus;
	int		exit_code;

	exit_code = EXIT_SUCCESS;
	if (waitpid(pid, &wstatus, 0) != -1)
	{
		if (WIFEXITED(wstatus))
			exit_code = WEXITSTATUS(wstatus);
		else if (WIFSIGNALED(wstatus))
			exit_code = WTERMSIG(wstatus) + 128;
	}
	while (wait(NULL) != -1)
		;
	return (exit_code);
}

/*
*/
static int	ft_exec_1cmd(t_shell *shell, t_list *cmd, int *pipefd, int *fd)
{
	pid_t		pid;
	t_cmd_table	*cmd_table;

	cmd_table = (t_cmd_table *) cmd->content;
	if (pipe(pipefd) == -1)
		return (ft_cleanup(shell), exit(ft_print_error("pipe", NULL)), -1);
	pid = fork();
	if (pid == -1)
	{
		close(pipefd[0]);
		close(pipefd[1]);
		return (ft_cleanup(shell), exit(ft_print_error("fork", NULL)), -1);
	}
	if (pid == 0)
		ft_exec_child(shell, cmd_table, pipefd, fd);
	else
		ft_exec_parent(shell, cmd_table, pipefd, fd);
	return (pid);
}

/*
*/
static void	ft_exec_parent(t_shell *s, t_cmd_table *cmd, int *pipefd, int *fd)
{
	close(pipefd[1]);
	if (cmd->cmd_nmb != 0)
		close(*fd);
	*fd = pipefd[0];
	if (cmd->cmd_nmb == s->cmds_nmb - 1)
		close(pipefd[0]);
}

void	ft_recall_builtin(t_shell *shell, t_cmd_table *cmd_table, int flag)
{
	if (cmd_table->builtin_id == EXIT_BUILTIN)
		builtin_exit(shell, cmd_table->args, flag);
	else if (cmd_table->builtin_id == ECHO_BUILTIN)
		builtin_echo(shell, cmd_table->args, flag, cmd_table->outfd);
	else if (cmd_table->builtin_id == ENV_BUILTIN)
		builtin_env(shell, cmd_table->args, flag, cmd_table->outfd);
	else if (cmd_table->builtin_id == PWD_BUILTIN)
		builtin_pwd(shell, cmd_table->args, flag, cmd_table->outfd);
	else if (cmd_table->builtin_id == EXPORT_BUILTIN)
		builtin_export(shell, cmd_table->args, flag, cmd_table->outfd);
	else if (cmd_table->builtin_id == UNSET_BUILTIN)
		builtin_unset(shell, cmd_table->args, flag);
	else if (cmd_table->builtin_id == CD_BUILTIN)
		builtin_cd(shell, cmd_table->args, flag, cmd_table->outfd);
}
