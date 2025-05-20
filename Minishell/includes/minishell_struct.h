/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_struct.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:14:59 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 11:07:16 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_STRUCT_H
# define MINISHELL_STRUCT_H

# include <libft.h>

//	Linked list that contains the tokens obtained from the prompt line
typedef struct s_cmd_line
{
	char				*str;	/*	Argument string							*/
	int					flag;	/*	Token identifier						*/
	struct s_cmd_line	*next;	/*	Pointer to the next node				*/
}				t_cmd_line;

//	Structure of a token of the prompt line
typedef struct s_token
{
	char	*str;				/*	Argument string							*/
	int		flag;				/*	Argument type (see enum e_trallalero..)	*/
}				t_token;

//	Unsigned char abbreviation
typedef unsigned char		t_uchar;

//	Struct sigaction abbreviation
typedef struct sigaction	t_sig;

//	Big structure which contains everything is needed to manage a command line
typedef struct s_shell
{
	t_cmd_line	*cmd_line;		/*	List of tokens written in the prompt	*/
	char		*str;			/*	String written in the prompt			*/
	t_list		*cmd_tables;	/*	Command tables to be executed			*/
	t_list		*envp;			/*	Environment variables list				*/
	char		**env_paths;	/*	Paths of executables					*/
	char		**env_vars;		/*	Environment variables matrix			*/
	int			cmds_nmb;		/*	Number of commands in cmd_tables		*/
	t_uchar		exit_status;	/*	Exit status of the previous command		*/
}				t_shell;

//	Structure which contains the info to execute a command
typedef struct s_cmd_table
{
	int		infd;				/*	Input fd for the command				*/
	int		outfd;				/*	Output fd for the command				*/
	int		builtin_flag;		/*	Command is builtin yes or no			*/
	int		builtin_id;			/*	ID for which builtin is					*/
	char	*path;				/*	Executable path / name of builtin		*/
	char	**args;				/*	Command arguments						*/
	int		cmd_nmb;			/*	Command position in the line			*/
	int		heredoc_flag;		/*	Infd is heredoc yes or no				*/
	char	*heredoc_filename;	/*	Name of the heredoc file				*/
	int		heredoc_exp;		/*	Variable expansion in heredoc yes or no	*/
	int		cmd_noprint;		/*	Don't print error message yes or no		*/
}				t_cmd_table;

#endif