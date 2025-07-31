/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_add_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:16:12 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/15 10:45:27 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

static void	ft_append_variable(t_shell *shell, char *arg);
static char	*ft_actual_append(char *str, t_list *var);
static void	ft_simple_add_append(t_shell *shell, char *arg);

t_uchar	ft_add_variables(t_shell *shell, char **args)
{
	size_t	i;
	t_uchar	exit_code;
	t_uchar	tmp;
	char	*equal_position;

	i = 1;
	exit_code = ERR_SUCCESS;
	while (args[i] != NULL)
	{
		tmp = export_check_invalid_identifier(args[i]);
		if (tmp != ERR_SUCCESS)
			exit_code = tmp;
		else
		{
			equal_position = ft_strchr(args[i], '=');
			if (equal_position != NULL && *(equal_position - 1) == '+')
				ft_append_variable(shell, args[i]);
			else
				ft_simple_add(shell, args[i]);
		}
		i++;
	}
	return (exit_code);
}

void	ft_simple_add(t_shell *shell, char *arg)
{
	char	*str;
	t_list	*new_node;
	t_list	*variable;

	if (arg == NULL || shell == NULL)
		return ;
	variable = node_of_variable_if_present(shell, arg);
	if (variable != NULL && ft_strchr(arg, '=') == NULL)
		return ;
	str = ft_strdup(arg);
	if (str == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno));
	new_node = ft_lstnew(str);
	if (new_node == NULL)
		return (free(str), ft_malloc_error(shell, ft_cleanup), exit(errno));
	if (variable != NULL)
		ft_lstrmnode(&(shell->envp), variable, free);
	if (shell->envp == NULL)
		shell->envp = new_node;
	else
		ft_lstadd_back(&(shell->envp), new_node);
}

static void	ft_append_variable(t_shell *shell, char *arg)
{
	char	*str;
	char	*tmp;
	t_list	*variable;

	if (arg == NULL || shell == NULL)
		return ;
	variable = node_of_variable_if_present(shell, arg);
	if (variable == NULL)
		return (ft_simple_add_append(shell, arg));
	while (*arg != '\0' && *arg != '=')
		arg++;
	arg++;
	str = ft_strdup(arg);
	if (str == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno));
	tmp = ft_actual_append(str, variable);
	if (tmp == NULL)
		return (free(str), ft_malloc_error(shell, ft_cleanup), exit(errno));
	free(variable->content);
	free(str);
	variable->content = (void *) tmp;
}

static char	*ft_actual_append(char *str, t_list *var)
{
	char	*tmp1;
	char	*tmp2;

	if (ft_strchr((char *) var->content, '=') == NULL)
	{
		tmp1 = ft_strjoin((char *) var->content, "=");
		if (tmp1 == NULL)
			return (NULL);
		tmp2 = ft_strjoin(tmp1, str);
		free(tmp1);
		if (tmp2 == NULL)
			return (NULL);
	}
	else
	{
		tmp2 = ft_strjoin((char *) var->content, str);
		if (tmp2 == NULL)
			return (NULL);
	}
	return (tmp2);
}

static void	ft_simple_add_append(t_shell *shell, char *arg)
{
	size_t	i;
	size_t	j;
	char	*str;
	t_list	*new_node;

	if (arg == NULL || shell == NULL)
		return ;
	str = ft_calloc(ft_strlen(arg), sizeof(char));
	if (str == NULL)
		return (ft_malloc_error(shell, ft_cleanup), exit(errno));
	i = 0;
	j = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] == '+')
			i++;
		str[j] = arg[i];
		j++;
		i++;
	}
	new_node = ft_lstnew(str);
	if (new_node == NULL)
		return (free(str), ft_malloc_error(shell, ft_cleanup), exit(errno));
	ft_lstadd_back(&(shell->envp), new_node);
}
