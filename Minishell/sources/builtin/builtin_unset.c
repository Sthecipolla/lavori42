/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:09:45 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 12:04:56 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

static t_uchar	ft_rm_variables(t_shell *shell, char **args);

void	builtin_unset(t_shell *shell, char **args, int flag)
{
	t_uchar	exit_code;
	size_t	i;

	exit_code = ERR_SUCCESS;
	if (args != NULL)
	{
		exit_code = check_options(args, UNSET_NAME, UNSET_BUILTIN);
		if (exit_code == ERR_SUCCESS)
		{
			i = 0;
			while (args[i] != NULL)
				i++;
			if (i > 1)
				exit_code = ft_rm_variables(shell, args);
		}
	}
	if (flag == CHILD)
		return (ft_cleanup(shell), exit(exit_code));
	else
		return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
}

static t_uchar	ft_rm_variables(t_shell *shell, char **args)
{
	size_t	i;
	t_uchar	exit_code;
	t_uchar	tmp;
	t_list	*variable;

	i = 0;
	exit_code = ERR_SUCCESS;
	while (args[i] != NULL)
	{
		tmp = unset_check_invalid_identifier(args[i]);
		if (tmp != ERR_SUCCESS)
			exit_code = tmp;
		else
		{
			variable = node_of_variable_if_present(shell, args[i]);
			if (variable != NULL)
				ft_lstrmnode(&(shell->envp), variable, free);
		}
		i++;
	}
	return (exit_code);
}
