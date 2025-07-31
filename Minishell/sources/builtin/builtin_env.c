/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:03:55 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/15 15:27:10 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <builtin/minishell_builtin.h>

static int		ft_print_env_variable(char *str, int outfd);

void	builtin_env(t_shell *shell, char **args, int flag, int outfd)
{
	t_list	*tmp_list;
	t_uchar	exit_code;

	exit_code = ERR_SUCCESS;
	if (args != NULL)
	{
		exit_code = check_options(args, ENV_NAME, ENV_BUILTIN);
		if (exit_code == ERR_SUCCESS)
		{
			tmp_list = shell->envp;
			while (tmp_list != NULL)
			{
				if (ft_print_env_variable((char *) tmp_list->content, outfd) \
					== ERROR)
					break ;
				tmp_list = tmp_list->next;
			}
		}
	}
	if (g_sig_status == (SIGPIPE + 128))
		exit_code = SIGPIPE + 128;
	if (flag == CHILD)
		return (ft_cleanup(shell), exit(exit_code));
	else
		return (shell->exit_status = exit_code, ft_return_to_prompt(shell));
}

static int	ft_print_env_variable(char *str, int outfd)
{
	char	*tmp;
	char	error;

	error = 0;
	tmp = str;
	if (ft_isdigit(*tmp) == TRUE)
		return (error);
	while (*tmp != '\0')
	{
		if (*tmp == '=')
		{
			error = ft_dprintf(outfd, "%s\n", str);
			break ;
		}
		tmp++;
	}
	return (error);
}
