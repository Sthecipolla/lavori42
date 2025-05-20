/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_env_vars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:32:04 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 12:46:05 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <execute/minishell_execute.h>

static char	**ft_parse_env_paths(t_shell *shell);
static char	**ft_env_list_to_matrix(t_list *envp);

void	ft_set_environment(t_shell *shell)
{
	char	**env_paths;
	char	**env_vars;

	env_paths = ft_parse_env_paths(shell);
	env_vars = ft_env_list_to_matrix(shell->envp);
	if (env_vars == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno));
	shell->env_paths = env_paths;
	shell->env_vars = env_vars;
}

static char	**ft_parse_env_paths(t_shell *shell)
{
	char	**env_paths;
	char	*tmp_str;
	t_list	*tmp_list;

	tmp_list = shell->envp;
	while (tmp_list != NULL)
	{
		tmp_str = (char *) tmp_list->content;
		if (ft_strnstr(tmp_str, "PATH=", 5) != NULL)
			break ;
		tmp_list = tmp_list->next;
	}
	if (tmp_list == NULL)
		return (NULL);
	tmp_str += 5;
	env_paths = ft_split(tmp_str, ':');
	if (env_paths == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno), NULL);
	return (env_paths);
}

static char	**ft_env_list_to_matrix(t_list *envp)
{
	char	**env_vars;
	int		len_list;
	int		i;

	len_list = ft_lstsize(envp);
	env_vars = (char **) ft_calloc(len_list + 1, sizeof(char *));
	if (env_vars == NULL)
		return (NULL);
	env_vars[len_list] = NULL;
	i = 0;
	while (envp != NULL)
	{
		env_vars[i] = ft_strdup((char *) envp->content);
		if (env_vars[i] == NULL)
			return (ft_free_char_matrix2(env_vars), NULL);
		envp = envp->next;
		i++;
	}
	return (env_vars);
}
