/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_error_codes.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:51:11 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/19 15:20:00 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERROR_CODES_H
# define MINISHELL_ERROR_CODES_H

//	Bash error codes
# define ERR_SUCCESS	0		/*	Success						*/
# define ERR_GENERAL	1		/*	General error				*/
# define ERR_BUILTIN	2		/*	Misuse of shell builtins	*/
# define ERR_INVOPT		125		/*	Invalid option				*/
# define ERR_PERM		126		/*	Permission denied			*/
# define ERR_NOTFOUND	127		/*	Command not found			*/
# define ERR_INVEXIT	128		/*	Invalid argument to exit	*/
# define ERR_CONTROLC	130		/*	Terminated by Control-C		*/
# define ERR_SYNTAX		2		/*	Syntax error				*/

//	Unix error codes
# include <errno.h>
# define E2SMALL 		41		/*	Argument list too short		*/
# define ENOCMD 		58		/*	Command not found			*/
# define EAMBRED		134		/*	Ambiguos redirect			*/

//	Personalized error messages
# define E2SMALL_MSG	"Argument list too short"
# define ENOCMD_MSG		"Command not found"
# define NOFILE_MSG		"No such file or directory"
# define EAMBRED_MSG	"Ambiguos redirect"

#endif