/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 10:47:08 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/15 14:06:46 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

#define WARNING "warning"
#define HERE_DOC_MSG "here-document delimited by end-of-file"

static int	ft_open_heredoc(t_shell *shell, t_cmd_table *table, char *limiter);
static void	ft_here_doc2(t_shell *shell, char *limiter, int fd, int exp_flag);
static int	check_exit_from_heredoc(int stdin_dup, char *limiter, char *str);

int	ft_set_heredoc_fd(t_shell *shell, t_cmd_table *table, t_cmd_line **line)
{
	if ((*line)->flag == HERE_DOC)
		table->heredoc_exp = TRUE;
	(*line) = (*line)->next;
	if (*line == NULL)
		return (-1);
	if (table->infd != STDIN_FILENO)
		close(table->infd);
	if (ft_open_heredoc(shell, table, (*line)->str) == ERROR)
		return (-1);
	table->heredoc_flag = TRUE;
	ft_here_doc2(shell, (*line)->str, table->infd, table->heredoc_exp);
	close(table->infd);
	table->infd = open(table->heredoc_filename, O_RDONLY);
	if (table->infd == -1)
		return (ft_print_error(PROG_NAME, (*line)->str), -1);
	(*line) = (*line)->next;
	if (g_sig_status == (SIGINT + 128))
	{
		shell->exit_status = SIGINT + 128;
		return (ft_free_cmd_table(table), HEREDOC_SIGINT);
	}
	return (table->infd);
}

static int	ft_open_heredoc(t_shell *shell, t_cmd_table *table, char *limiter)
{
	char	*filename;
	char	*tmp;

	if (table->heredoc_filename == NULL)
	{
		tmp = ft_itoa(table->cmd_nmb);
		if (tmp == NULL)
			return (ft_free_cmd_table(table), \
				ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
		filename = ft_strjoin(".heredoc_", tmp);
		free(tmp);
		if (filename == NULL)
			return (ft_free_cmd_table(table), \
				ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
		table->heredoc_filename = filename;
	}
	else
		filename = table->heredoc_filename;
	table->infd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (table->infd == -1)
		return (ft_print_error("open", limiter), ERROR);
	return (ERR_SUCCESS);
}

static void	ft_here_doc2(t_shell *shell, char *limiter, int fd, int exp_flag)
{
	char	*str;
	char	*tmp;
	int		stdin_dup;

	ft_manage_sigint_heredoc(shell);
	stdin_dup = dup(STDIN_FILENO);
	while (TRUE)
	{
		str = readline("> ");
		if (check_exit_from_heredoc(stdin_dup, limiter, str) == TRUE)
			break ;
		if (exp_flag == TRUE)
		{
			tmp = str;
			str = expand_variable(str, shell);
			free(tmp);
			if (str == NULL)
				return (ft_malloc_error(shell, ft_cleanup), exit(errno));
		}
		ft_dprintf(fd, "%s\n", str);
		free(str);
	}
	def_signal(shell);
	return (close(stdin_dup), free(str));
}

static int	check_exit_from_heredoc(int stdin_dup, char *limiter, char *str)
{
	if (g_sig_status == (SIGINT + 128))
	{
		dup2(stdin_dup, STDIN_FILENO);
		return (TRUE);
	}
	else if (str == NULL)
	{
		ft_dprintf(STDERR_FILENO, "%s: %s: %s (wanted `%s\')\n", \
			PROG_NAME, WARNING, HERE_DOC_MSG, limiter);
		return (TRUE);
	}
	else if (ft_strncmp(limiter, str, ft_strlen(limiter) + 1) == 0)
		return (TRUE);
	return (FALSE);
}
