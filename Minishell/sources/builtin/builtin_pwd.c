/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 10:08:05 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 22:11:44 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

void	builtin_pwd(t_shell *shell, char **args, int flag, int outfd)
{
	char	*pwd;
	t_uchar	exit_code;

	exit_code = ERR_SUCCESS;
	if (args != NULL)
	{
		exit_code = check_options(args, PWD_NAME, PWD_BUILTIN);
		if (exit_code == ERR_SUCCESS)
		{
			pwd = getcwd(NULL, 0);
			if (pwd == NULL)
				return (ft_malloc_error(shell, ft_cleanup), exit(errno));
			ft_dprintf(outfd, "%s\n", pwd);
			free(pwd);
		}
	}
	if (g_sig_status == (SIGPIPE + 128))
		exit_code = SIGPIPE + 128;
	if (flag == CHILD)
		return (ft_cleanup(shell), exit(exit_code));
	else
		return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
}
