/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_men.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:18:29 by lhima             #+#    #+#             */
/*   Updated: 2025/01/31 13:44:14 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void print_error(int error)
{
	if(error == 0)
		return ;
	if(error == 1)
		write(2,"Error\nnumber < 2\n",17);
	if(error == 2)
		write(2,"Error\nnumber invalid\n",21);
	if(error == 3)
		write(2, "Error\nnumber > int max\n", 23);
	if(error == 4)
		write(2,"Error\nduplicates\n",17);
}
