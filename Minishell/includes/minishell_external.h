/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_external.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:11:52 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/12 14:16:54 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXTERNAL_H
# define MINISHELL_EXTERNAL_H

//	This solves the syntax error problem in vscode with sigaction
# define _XOPEN_SOURCE 700

//	Libft functions
# include <libft.h>

//	External functions allowed by the subject
# include <readline/readline.h>		/*	readline							*/
# include <readline/history.h>		/*	rl_clear_history, rl_on_new_line,	*/
									/*	rl_replace_line, rl_display,		*/
									/*	add_history							*/
# include <stdio.h>					/*	printf, perror						*/
# include <stdlib.h>				/*	malloc, free, exit, getenv			*/
# include <unistd.h>				/*	write, access, read, close, fork,	*/
									/*	getcwd, chdir, unlink, execve, dup,	*/
									/*	dup2, pipe, isatty, ttyname, 		*/
									/*	ttyslot, tcsetattr, tcgetattr		*/
# include <fcntl.h>					/*	open								*/
# include <sys/wait.h>				/*	wait, waitpid, wait3, wait4			*/
# include <signal.h>				/*	signal, sigaction, sigemptyset,		*/
									/*	sigaddset, kill						*/
# include <sys/stat.h>				/*	stat, lstat, fstat					*/
# include <dirent.h>				/*	opendir, readdir, closedir			*/
# include <string.h>				/*	strerror							*/
# include <sys/ioctl.h>				/*	ioctl								*/
# include <term.h>					/*	tgetent, tgetflag, tgetnum, 		*/
									/*	tgetstr, tgoto, tputs				*/

#endif