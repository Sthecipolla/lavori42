/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:15:01 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 22:02:46 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_shared.h>
#include <signals/minishell_signals.h>

#define SIGACTION_NAME "sigaction"

/*
Ctrl + C - SIGINT
Ctrl + \ - SIGQUIT
*/
// nei processi le cose si duplicano quindi devi richiamare questa
// funzione per riasegnarli correttamente altrimenti con ctrl + C
// va a capo 2 volte
int	def_signal(t_shell *shell)
{
	t_sig	sigint;
	t_sig	sigquit;

	sigemptyset(&sigint.sa_mask);
	sigint.sa_flags = SA_RESTART;
	sigint.sa_handler = sigint_handle;
	if (sigaction(SIGINT, &sigint, NULL) != 0)
		return (ft_print_error(SIGACTION_NAME, NULL), ft_cleanup(shell), \
			exit(errno), ERR_GENERAL);
	sigemptyset(&sigquit.sa_mask);
	sigquit.sa_flags = SA_RESTART;
	sigquit.sa_handler = SIG_IGN;
	if (sigaction(SIGQUIT, &sigquit, NULL) != 0)
		return (ft_print_error(SIGACTION_NAME, NULL), ft_cleanup(shell), \
			exit(errno), ERR_GENERAL);
	return (ERR_SUCCESS);
}

void	ft_reset_signals_to_default(t_shell *shell)
{
	t_sig	sigint;
	t_sig	sigquit;

	sigemptyset(&sigint.sa_mask);
	sigint.sa_flags = SA_RESTART;
	sigint.sa_handler = SIG_DFL;
	if (sigaction(SIGINT, &sigint, NULL) != 0)
		return (ft_print_error(SIGACTION_NAME, NULL), ft_cleanup(shell), \
			exit(errno));
	sigemptyset(&sigquit.sa_mask);
	sigquit.sa_flags = SA_RESTART;
	sigquit.sa_handler = SIG_DFL;
	if (sigaction(SIGQUIT, &sigquit, NULL) != 0)
		return (ft_print_error(SIGACTION_NAME, NULL), ft_cleanup(shell), \
			exit(errno));
}

void	ft_avoid_sigpipe(t_shell *shell)
{
	t_sig	sigpipe;

	sigemptyset(&sigpipe.sa_mask);
	sigpipe.sa_flags = SA_RESTART;
	sigpipe.sa_handler = handle_sigpipe_builtin;
	if (sigaction(SIGPIPE, &sigpipe, NULL) != 0)
		return (ft_print_error(SIGACTION_NAME, NULL), ft_cleanup(shell), \
			exit(errno));
}

void	ft_manage_sigint_heredoc(t_shell *shell)
{
	t_sig	sigint;

	sigemptyset(&sigint.sa_mask);
	sigint.sa_flags = SA_RESTART;
	sigint.sa_handler = handle_sigint_here_doc;
	if (sigaction(SIGINT, &sigint, NULL) != 0)
		return (ft_print_error(SIGACTION_NAME, NULL), ft_cleanup(shell), \
			exit(errno));
}
