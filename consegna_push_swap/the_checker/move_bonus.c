/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:15:00 by lhima             #+#    #+#             */
/*   Updated: 2025/02/24 15:49:50 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_move(char *line, t_lista **a, t_lista **b)
{
	if (ft_strncmp(line, "sa", 2) == 0)
		cswap_a((*a));
	else if (ft_strncmp(line, "sb", 2) == 0)
		cswap_b((*b));
	else if (ft_strncmp(line, "ss", 2) == 0)
		cswap_ss((*a), (*b));
	else if (ft_strncmp(line, "pa", 2) == 0)
		cpush_a(b, a);
	else if (ft_strncmp(line, "pb", 2) == 0)
		cpush_b(a, b);
	else if (ft_strncmp(line, "rra", 3) == 0)
		creverse_a(a);
	else if (strncmp(line, "rrb", 3) == 0)
		creverse_b(b);
	else if (ft_strncmp(line, "rrr", 3) == 0)
		creverse_rr(a, b);
	else if (ft_strncmp(line, "ra", 2) == 0)
		crotate_a(a);
	else if (ft_strncmp(line, "rb", 2) == 0)
		crotate_b(b);
	else if (ft_strncmp(line, "rr", 2) == 0)
		crotate_rr(a, b);
	else
		return (1);
	return (0);
}
