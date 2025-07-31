/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_builtin.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:23:33 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 21:52:42 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BUILTIN_H
# define MINISHELL_BUILTIN_H

# include <minishell_shared.h>

//	Variable limits
# include <limits.h>

//	Generic error messages
# define TOO_MANY_ARGS_MSG "too many arguments"
# define INVALID_OPTION_MSG "invalid option"
# define INVALID_ID_MSG "not a valid identifier"

//	Defines for exit
# define EXIT_NUMERIC_MSG "numeric argument required"

//	Defines for echo
typedef struct s_echo_options
{
	int	n;
	int	e;
}				t_echo_options;

//	Prototypes of functions in file builtin/builtin_export_print_utils.c
void	ft_print_variables(t_shell *shell, int outfd);

//	Prototypes of functions in file builtin/builtin_export_add_utils.c
t_uchar	ft_add_variables(t_shell *shell, char **args);
void	ft_simple_add(t_shell *shell, char *arg);

//	Prototypes of functions in file builtin/builtin_utils.c
t_uchar	check_options(char **args, char *func_name, int builtin_id);
t_uchar	export_check_invalid_identifier(char *arg);
t_uchar	unset_check_invalid_identifier(char *arg);
t_list	*node_of_variable_if_present(t_shell *shell, char *arg);
void	*ft_void_strdup(void *p);

#endif
