/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_path_finder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:21:22 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 11:13:19 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

static char	**ft_build_args(t_cmd_line **line);
static void	ft_check_builtin(t_cmd_table *table);
static char	*ft_build_path(t_shell *shell, t_cmd_table *table);

int	ft_set_command(t_shell *shell, t_cmd_table *table, t_cmd_line **line)
{
	if ((*line)->flag == EMPTY)
		table->cmd_noprint = TRUE;
	table->args = ft_build_args(line);
	if (table->args == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
	ft_check_builtin(table);
	table->path = ft_build_path(shell, table);
	if (table->path == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), ERROR);
	return (EXIT_SUCCESS);
}

static char	**ft_build_args(t_cmd_line **line)
{
	t_cmd_line	*tmp;
	size_t		args_count;
	size_t		i;
	char		**args;

	args_count = 1;
	tmp = (*line)->next;
	while (tmp != NULL && tmp->flag == ARG)
	{
		args_count++;
		tmp = tmp->next;
	}
	args = (char **) ft_calloc(args_count + 1, sizeof(char *));
	if (args == NULL)
		return (NULL);
	i = 0;
	while (i < args_count)
	{
		args[i] = ft_strdup((*line)->str);
		if (args[i] == NULL)
			return (ft_free_char_matrix2(args), NULL);
		(*line) = (*line)->next;
		i++;
	}
	return (args);
}

static void	ft_check_builtin(t_cmd_table *table)
{
	if (ft_strncmp(table->args[0], EXIT_NAME, ft_strlen(EXIT_NAME) + 1) == 0)
		table->builtin_id = EXIT_BUILTIN;
	else if (ft_strncmp(table->args[0], ECHO_NAME, \
				ft_strlen(ECHO_NAME) + 1) == 0)
		table->builtin_id = ECHO_BUILTIN;
	else if (ft_strncmp(table->args[0], ENV_NAME, ft_strlen(ENV_NAME) + 1) == 0)
		table->builtin_id = ENV_BUILTIN;
	else if (ft_strncmp(table->args[0], PWD_NAME, ft_strlen(PWD_NAME) + 1) == 0)
		table->builtin_id = PWD_BUILTIN;
	else if (ft_strncmp(table->args[0], EXPORT_NAME, \
			ft_strlen(EXPORT_NAME) + 1) == 0)
		table->builtin_id = EXPORT_BUILTIN;
	else if (ft_strncmp(table->args[0], UNSET_NAME, \
			ft_strlen(UNSET_NAME) + 1) == 0)
		table->builtin_id = UNSET_BUILTIN;
	else if (ft_strncmp(table->args[0], CD_NAME, ft_strlen(CD_NAME) + 1) == 0)
		table->builtin_id = CD_BUILTIN;
	if (table->builtin_id != -1)
		table->builtin_flag = TRUE;
}

static char	*ft_build_path(t_shell *shell, t_cmd_table *table)
{
	char	*cmd_path;
	char	*tmp;
	size_t	i;

	i = 0;
	if (shell->env_paths == NULL)
		return (ft_strdup(table->args[0]));
	while (shell->env_paths[i] != NULL)
	{
		cmd_path = ft_strjoin(shell->env_paths[i], "/");
		if (cmd_path == NULL)
			return (ft_malloc_error(shell, ft_cleanup), exit(errno), NULL);
		tmp = cmd_path;
		cmd_path = ft_strjoin(tmp, table->args[0]);
		free(tmp);
		if (cmd_path == NULL)
			return (ft_malloc_error(shell, ft_cleanup), exit(errno), NULL);
		if (access(cmd_path, X_OK) == 0)
			break ;
		i++;
		free(cmd_path);
	}
	if (shell->env_paths[i] == NULL)
		return (ft_strdup(table->args[0]));
	return (cmd_path);
}
