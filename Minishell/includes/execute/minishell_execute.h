/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_execute.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:05:54 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/20 13:19:45 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTE_H
# define MINISHELL_EXECUTE_H

# include <minishell_shared.h>

# define HEREDOC_SIGINT -2

//	Prototypes of functions in file execute/line_to_table.c
void	ft_line_to_table(t_shell *shell);

//	Prototypes of functions in file execute/reorder_cmd_line.c
void	reorder_cmd_line(t_shell *s, t_cmd_line *line);

//	Prototypes of functions in file execute/reorder_cmd_line_utils.c
int		ft_isredir(int flag);
void	ft_conc_cmdline(t_cmd_line **l, t_cmd_line *conc);
int		ft_dup_add_node(t_shell *s, t_cmd_line **lst, t_cmd_line *toadd);

//	Prototypes of functions in file execute/redirections.c
int		ft_set_input_fd(t_cmd_table *table, t_cmd_line **line);
int		ft_set_output_fd(t_cmd_table *table, t_cmd_line **line);
int		ft_set_append_fd(t_cmd_table *table, t_cmd_line **line);

//	Prototypes of functions in file execute/execute.c
int		ft_exec_allcmd(t_shell *shell);
void	ft_recall_builtin(t_shell *shell, t_cmd_table *cmd_table, int flag);

//	Prototypes of functions in file execute/execute_utils.c
//	VOID

//	Prototypes of functions in file execute/execute_child.c
void	ft_exec_child(t_shell *s, t_cmd_table *table, int *pipefd, int *fd);

//	Prototypes of functions in file execute/here_doc.c
int		ft_set_heredoc_fd(t_shell *s, t_cmd_table *table, t_cmd_line **line);

//	Prototypes of functions in file execute/line_to_table_utils.c
void	ft_init_cmd_table(t_cmd_table *table, int i);
void	ft_fast_forward_to_next_pipe(t_cmd_line **line);
void	ft_set_cmd_to_null(t_cmd_table *table);

//	Prototypes of functions in file execute/manage_env_vars.c
void	ft_set_environment(t_shell *shell);

//	Prototypes of functions in file execute/args_path_finder.c
int		ft_set_command(t_shell *shell, t_cmd_table *table, t_cmd_line **line);

#endif