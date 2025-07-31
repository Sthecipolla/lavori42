/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:16:50 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 17:40:25 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

void	builtin_export(t_shell *shell, char **args, int flag, int outfd)
{
	t_uchar	exit_code;
	size_t	i;

	exit_code = ERR_SUCCESS;
	if (args != NULL)
	{
		exit_code = check_options(args, EXPORT_NAME, EXPORT_BUILTIN);
		if (exit_code == ERR_SUCCESS)
		{
			i = 0;
			while (args[i] != NULL)
				i++;
			if (i < 2)
				ft_print_variables(shell, outfd);
			else
				exit_code = ft_add_variables(shell, args);
		}
	}
	if (g_sig_status == (SIGPIPE + 128))
		exit_code = SIGPIPE + 128;
	if (flag == CHILD)
		return (ft_cleanup(shell), exit(exit_code));
	else
		return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
}
