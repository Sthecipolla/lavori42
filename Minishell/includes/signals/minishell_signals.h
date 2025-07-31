/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_signals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:45:31 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 21:52:49 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SIGNALS_H
# define MINISHELL_SIGNALS_H

# include <minishell_shared.h>

//	Prototypes of functions in file signals/signal_handlers.c
void	sigint_handle(int sig);
void	handle_sigint_here_doc(int sig);
void	handle_sigpipe_builtin(int sig);

#endif