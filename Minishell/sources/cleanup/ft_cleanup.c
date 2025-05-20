/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cleanup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:33:35 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 16:36:29 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <cleanup/minishell_cleanup.h>

/*
*/
void	ft_cleanup(void *p)
{
	t_shell	*shell;

	if (p == NULL)
		return ;
	shell = (t_shell *) p;
	ft_lstclear(&(shell->envp), free);
	ft_free_cmd_line(&(shell->cmd_line));
	free(shell->str);
	shell->str = NULL;
	ft_lstclear(&(shell->cmd_tables), ft_free_cmd_table);
	ft_free_char_matrix2(shell->env_paths);
	shell->env_paths = NULL;
	ft_free_char_matrix2(shell->env_vars);
	shell->env_vars = NULL;
	free(shell);
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	close(STDERR_FILENO);
}

void	ft_return_to_prompt(void *p)
{
	t_shell	*shell;

	if (p == NULL)
		return ;
	shell = (t_shell *) p;
	ft_free_cmd_line(&(shell->cmd_line));
	free(shell->str);
	shell->str = NULL;
	ft_lstclear(&(shell->cmd_tables), ft_free_cmd_table);
	ft_free_char_matrix2(shell->env_paths);
	shell->env_paths = NULL;
	ft_free_char_matrix2(shell->env_vars);
	shell->env_vars = NULL;
}

/*
*/
void	ft_free_cmd_line(t_cmd_line **cmd)
{
	t_cmd_line	*tmp;

	if (cmd != NULL)
	{
		tmp = *cmd;
		while (tmp != NULL)
		{
			tmp = (*cmd)->next;
			free((*cmd)->str);
			free(*cmd);
			*cmd = tmp;
		}
	}
}

void	ft_free_cmd_table(void *p)
{
	t_cmd_table	*table;

	if (p == NULL)
		return ;
	table = (t_cmd_table *) p;
	if (table->path != NULL)
		free(table->path);
	table->path = NULL;
	ft_free_char_matrix2(table->args);
	table->args = NULL;
	if (table->infd != STDIN_FILENO && table->infd != -1)
		close(table->infd);
	if (table->outfd != STDOUT_FILENO && table->outfd != -1)
		close(table->outfd);
	if (table->heredoc_flag == TRUE && table->heredoc_filename != NULL)
		unlink(table->heredoc_filename);
	if (table->heredoc_filename != NULL)
		free(table->heredoc_filename);
	free(table);
}

void	ft_close_fds_cmd_table(void *p)
{
	t_cmd_table	*table;

	table = (t_cmd_table *) p;
	if (table->infd != STDIN_FILENO)
		close(table->infd);
	if (table->outfd != STDOUT_FILENO)
		close(table->outfd);
}

/* void	ft_free_token(void *p)
{
	t_token	*token;

	token = (t_token *) p;
	free(token->str);
	free(token);
} */
