/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:15:00 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 17:14:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	nor(char *l)
{
	return (ft_strlen(l) - 1);
}

int	check_move(char *line, t_lista **a, t_lista **b)
{
	if (ft_strncmp(line, "sa", nor(line)) == 0)
		cswap_a((*a));
	else if (ft_strncmp(line, "sb", nor(line)) == 0)
		cswap_b((*b));
	else if (ft_strncmp(line, "ss", nor(line)) == 0)
		cswap_ss((*a), (*b));
	else if (ft_strncmp(line, "pa", nor(line)) == 0)
		cpush_a(b, a);
	else if (ft_strncmp(line, "pb", nor(line)) == 0)
		cpush_b(a, b);
	else if (ft_strncmp(line, "rra", nor(line)) == 0)
		creverse_a(a);
	else if (strncmp(line, "rrb", nor(line)) == 0)
		creverse_b(b);
	else if (ft_strncmp(line, "rrr", nor(line)) == 0)
		creverse_rr(a, b);
	else if (ft_strncmp(line, "ra", nor(line)) == 0)
		crotate_a(a);
	else if (ft_strncmp(line, "rb", nor(line)) == 0)
		crotate_b(b);
	else if (ft_strncmp(line, "rr", nor(line)) == 0)
		crotate_rr(a, b);
	else
		return (1);
	return (0);
}
/*
parametro "" = error
command rra          = error
command rr a = error
lekka se esco con ctrl + D (si pensa che non libera B)
*/
