/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_before_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:07:11 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 12:46:51 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

void	free_struct_cmd(t_cmd_line **cmd)
{
	t_cmd_line	*tmp;

	while ((*cmd) != NULL)
	{
		tmp = (*cmd)->next;
		free((*cmd)->str);
		free((*cmd));
		(*cmd) = tmp;
	}
}

void	free_list(t_list **cmd)
{
	t_list	*tmp;

	while ((*cmd) != NULL)
	{
		tmp = (*cmd)->next;
		if ((*cmd)->content != NULL)
			free((*cmd)->content);
		free((*cmd));
		(*cmd) = tmp;
	}
}

void	ft_clean(t_shell *shell, int error)
{
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
	ft_dprintf(STDERR_FILENO, "exit\n");
	close(STDOUT_FILENO);
	close(STDIN_FILENO);
	close(STDERR_FILENO);
	exit(error);
}
