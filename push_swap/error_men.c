/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_men.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:29 by lhima             #+#    #+#             */
/*   Updated: 2025/01/28 16:32:43 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void print_error(int error)
{
	if(error == 0)
		return ;
	if(error == 1)
		ft_printf("Error\nnumber < 2\n");
	if(error == 2)
		ft_printf("Error\nnumber invalid\n");
	if(error == 3)
		ft_printf("Error\nnumber > int max\n");
	if(error == 4)
		ft_printf("Error\nduplicates\n");
}
