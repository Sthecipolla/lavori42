/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:44:13 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 21:51:58 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <signals/minishell_signals.h>

void	sigint_handle(int sig)
{
	g_sig_status = sig + 128;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	if (rl_readline_state & RL_STATE_READCMD)
		rl_redisplay();
}

void	handle_sigint_here_doc(int sig)
{
	g_sig_status = sig + 128;
	write(STDIN_FILENO, "\n", 1);
	close(STDIN_FILENO);
}

void	handle_sigpipe_builtin(int sig)
{
	g_sig_status = sig + 128;
}
