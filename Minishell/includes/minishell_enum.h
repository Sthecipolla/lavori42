/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_enum.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:22:06 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 11:16:33 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ENUM_H
# define MINISHELL_ENUM_H

//	enum that defines argument types identifiers for tokens in command line
//	https://shorturl.at/PGv1T
enum	e_trallallero_trallalla
{
	COMMAND,
	ARG,
	SPECIAL,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HERE_DOC,
	HERE_DOC_NE,
	RED_APPEND,
	AMBIGUOUS,
	EMPTY,
};

//	enum that defines shell built-in identifiers
enum	e_builtin
{
	ECHO_BUILTIN,		/*	echo with option -n								*/
	CD_BUILTIN,			/*	cd with only a relative or absolute path		*/
	PWD_BUILTIN,		/*	pwd with no options								*/
	EXPORT_BUILTIN,		/*	*/
	UNSET_BUILTIN,		/*	*/
	ENV_BUILTIN,		/*	*/
	EXIT_BUILTIN,		/*	*/
};

//	enum that defines the flags for the builtin which let them know if they are
//	executed in a child process or directly in the parent process
enum	e_child_or_parent
{
	CHILD,
	PARENT,
};

#endif
