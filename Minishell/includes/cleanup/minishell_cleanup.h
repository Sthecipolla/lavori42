/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_cleanup.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:53:21 by daromoli          #+#    #+#             */
/*   Updated: 2025/04/29 13:02:12 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_CLEANUP_H
# define MINISHELL_CLEANUP_H

# include <minishell_shared.h>

//	Prototypes of functions in cleanup/free_char_matrixes.c
void	ft_free_char_matrix2(void *p);
void	ft_free_char_matrix3(void *p);

//	Prototypes of functions in cleanup/ft_cleanup.c
void	ft_cleanup(void *p);
void	ft_return_to_prompt(void *p);
void	ft_free_cmd_line(t_cmd_line **cmd);
void	ft_free_cmd_table(void *p);
void	ft_close_fds_cmd_table(void *p);
void	ft_free_token(void *p);

#endif