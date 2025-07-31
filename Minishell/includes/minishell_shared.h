/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_shared.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:27:10 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/12 14:18:30 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_SHARED_H
# define MINISHELL_SHARED_H

# include <minishell_external.h>
# include <minishell_struct.h>
# include <minishell_enum.h>
# include <minishell_error_codes.h>
# include <minishell_functions.h>

extern int	g_sig_status;

//	Program name
# define PROG_NAME		"minishell"

//	Builtin names
# define CD_NAME		"cd"
# define ECHO_NAME		"echo"
# define ENV_NAME		"env"
# define EXIT_NAME		"exit"
# define EXPORT_NAME	"export"
# define PWD_NAME		"pwd"
# define UNSET_NAME		"unset"

#endif
