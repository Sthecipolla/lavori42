/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:15:26 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 14:15:43 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../push_swap.h"

int		check_move(char *line, t_lista **a, t_lista **b);
int		checker(t_lista **a, t_lista **b);
void	cpush_a(t_lista **b, t_lista **a);
void	cpush_b(t_lista **a, t_lista **b);
void	cswap_a(t_lista *a);
void	cswap_b(t_lista *b);
void	cswap_ss(t_lista *a, t_lista *b);
void	crotate_a(t_lista **b);
void	crotate_b(t_lista **b);
void	crotate_rr(t_lista **a, t_lista **b);
void	creverse_a(t_lista **a);
void	creverse_b(t_lista **b);
void	creverse_rr(t_lista **a, t_lista **b);

#endif
