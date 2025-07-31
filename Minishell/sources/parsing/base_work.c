/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:07:20 by lhima             #+#    #+#             */
/*   Updated: 2025/05/16 12:28:49 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <parsing/minishell_parsing.h>

t_list	*ft_copy_env(char **env)
{
	t_list	*var;
	int		i;
	char	*string;
	t_list	*sti;

	if (env == NULL)
		return (NULL);
	i = -1;
	var = NULL;
	while (env[++i] != NULL)
	{
		string = ft_strdup(env[i]);
		if (string == NULL)
			return (ft_lstclear(&var, free), free(string), NULL);
		sti = ft_lstnew(string);
		if (sti == NULL)
			return (ft_lstclear(&var, free), free(string), free(sti), NULL);
		ft_lstadd_back(&var, sti);
	}
	return (var);
}

t_shell	*ft_trash(char **env, char **argv)
{
	t_list	*envp;
	t_shell	*trash;

	envp = ft_copy_env(env);
	if (envp == NULL)
		return (NULL);
	if (ft_positional_vars(&envp, argv) == ERROR)
		return (ft_lstclear(&envp, free), NULL);
	trash = malloc(sizeof(t_shell));
	if (trash == NULL)
		return (ft_lstclear(&envp, free), NULL);
	trash->envp = envp;
	trash->exit_status = 0;
	trash->str = NULL;
	trash->cmd_tables = NULL;
	trash->cmd_line = NULL;
	trash->env_paths = NULL;
	trash->env_vars = NULL;
	return (trash);
}

int	calc_flag(char *app, char *str, int i)
{
	if (app[0] == '<' && app[1] == '<')
	{
		i = skip_space(str, i);
		if (there_is_quotes(str, i) == TRUE)
			return (HERE_DOC_NE);
		return (HERE_DOC);
	}
	else if (app[0] == '>' && app[1] == '>')
		return (RED_APPEND);
	else if (app[0] == '>')
		return (REDIR_OUT);
	else if (app[0] == '<')
		return (REDIR_IN);
	return (-1);
}

int	ft_positional_vars(t_list **envp, char **argv)
{
	size_t	i;
	t_list	*new_node;
	char	*tmp1;
	char	*tmp2;

	if (argv == NULL)
		return (ERROR);
	i = -1;
	while (argv[++i] != NULL)
	{
		tmp1 = ft_itoa(i);
		if (tmp1 == NULL)
			return (ERROR);
		tmp2 = ft_safe_strjoin(tmp1, "=", 1);
		if (tmp2 == NULL)
			return (ERROR);
		tmp1 = ft_safe_strjoin(tmp2, argv[i], 1);
		if (tmp1 == NULL)
			return (ERROR);
		new_node = ft_lstnew(tmp1);
		if (new_node == NULL)
			return (free(tmp1), ERROR);
		ft_lstadd_back(envp, new_node);
	}
	return (ERR_SUCCESS);
}
