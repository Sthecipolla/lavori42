/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_functions.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:27:59 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 10:07:25 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_FUNCTIONS_H
# define MINISHELL_FUNCTIONS_H

# include <minishell_struct.h>

//	Functions in parsing
char	*expand_variable(char *str, t_shell *shell);
void	*ft_add_node(t_cmd_line **base, char *string, int flag);
char	*ft_safe_strjoin(char *s, char *s2, int frees);

//	Functions in errors
int		ft_print_error(char *func, char *s);
void	ft_malloc_error(void *p, void (*free)(void *));
int		ft_print_cmd_error(t_cmd_table *cmd);
char	*ft_strerror(int errnmb);

//	Function in cleanup
void	ft_free_char_matrix2(void *p);
void	ft_free_char_matrix3(void *p);
void	ft_cleanup(void *p);
void	ft_return_to_prompt(void *p);
void	ft_free_cmd_table(void *p);
void	ft_free_token(void *p);
void	ft_close_fds_cmd_table(void *p);
void	ft_free_cmd_line(t_cmd_line **cmd);

//	Functions in debug
void	ft_print_cmd_tables(t_shell *shell);
void	ft_print_atol_atoll(char *arg);
void	print_cmd_line(t_cmd_line *p);

//	Functions in execute
void	ft_line_to_table(t_shell *shell);
int		ft_exec_allcmd(t_shell *shell);

//	Funcions in signal
int		def_signal(t_shell *shell);
void	ft_reset_signals_to_default(t_shell *shell);
void	ft_avoid_sigpipe(t_shell *shell);
void	ft_manage_sigint_heredoc(t_shell *shell);

//	Functions in builtin
void	builtin_exit(t_shell *shell, char **args, int flag);
void	builtin_echo(t_shell *shell, char **args, int flag, int outfd);
void	builtin_env(t_shell *shell, char **args, int flag, int outfd);
void	builtin_pwd(t_shell *shell, char **args, int flag, int outfd);
void	builtin_export(t_shell *shell, char **args, int flag, int outfd);
void	builtin_unset(t_shell *shell, char **args, int flag);
void	builtin_cd(t_shell *shell, char **args, int flag, int outfd);

#endif