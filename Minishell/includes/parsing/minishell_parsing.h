/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parsing.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:06:24 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:47:33 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSING_H
# define MINISHELL_PARSING_H

# include <minishell_shared.h>

// ----------------------------------------------------------------------------
t_shell		*ft_trash(char **env, char **argv);
t_list		*ft_copy_env(char **env);
int			ft_positional_vars(t_list **envp, char **argv);
// ----------------------------------------------------------------------------
int			parsing(t_shell *trash);
void		before_do_echo(char *str);
char		*ft_safe_strjoin(char *s, char *s2, int frees);
void		free_matrix(char **matrix);
int			check_quotes(char *str);
t_cmd_line	*new_str(char *str);
int			skip_space(char *str, int i);
char		*ft_add_char(char **str, char c);
t_list		*ft_copy_env(char **env);

// ----------------------------------------------------------------------------
char		*ft_split_struct(char *str, int i, t_shell *p);
// ----------------------------------------------------------------------------

char		*expand_variable(char *str, t_shell *trash);
void		ft_clean(t_shell *trash, int error);
void		*ft_add_node(t_cmd_line **base, char *string, int flag);
void		free_struct_cmd(t_cmd_line **cmd);
void		*ft_space(char *str, int *i, char **app, t_cmd_line **arg);
// ----------------------------------------------------------------------------
char		*quotes(char *str, int *i, t_shell *t, char c);
// ----------------------------------------------------------------------------

int			all_same(char c, char *app);
int			calc_flag(char *app, char *str, int i);
int			vl_ch_en(char c);
char		*status(int exit_status);
// ----------------------------------------------------------------------------
int			start_checks(t_shell *trash, int *str);
int			count_here_doc(t_cmd_line *cmd, int len);
void		*ft_here_doc(char **ex, t_shell *tr);
int			ch_hdc(char *new_str);
void		just_write(char **new_str, char *str, int *i, t_shell *t);
int			calc_flag(char *app, char *str, int i);
int			there_is_quotes(char *str, int i);

//----------------------------------------------------

char		*normal_str(t_shell *t, char *str, int *i, char *app);
int			last_node_h(t_cmd_line *cmd, int change);
int			last_node_re(t_cmd_line *cmd);
char		*there_are_spaces(char *n_str, t_shell *t, char **app, int j);
char		*cmd_add_error(char	*str, int i);
int			only_one(t_cmd_line *arg, char *str, int i, int flag);

#endif
