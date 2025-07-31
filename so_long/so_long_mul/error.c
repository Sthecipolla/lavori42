/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:39:04 by lhima             #+#    #+#             */
/*   Updated: 2025/01/22 11:54:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_print(int error)
{
	if (error == 11)
		ft_printf("error\nmap\n");
	if (error == 12)
		ft_printf("error\nimg\n");
	if (error == 13)
		ft_printf("error\nreading file\n");
	return (0);
}
