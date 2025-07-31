/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_errors.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daromoli <daromoli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:45:41 by daromoli          #+#    #+#             */
/*   Updated: 2025/05/14 16:40:32 by daromoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_ERRORS_H
# define MINISHELL_ERRORS_H

# include <minishell_shared.h>

// Prototypes of functions in file errors/error_management.c
int		ft_print_error(char *func, char *s);
void	ft_malloc_error(void *p, void (*free)(void *));
int		ft_print_cmd_error(t_cmd_table *cmd);

#endif