/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:31 by lhima             #+#    #+#             */
/*   Updated: 2025/03/10 15:15:38 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	if_numeric(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while(str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
//maggiore o uguali di 0 il numero di pasti e i tempi error
int	checks(char **str)
{
	if (if_numeric(str) == 0)
	{
		perror("Error: arguments must be numeric\n");
		return (1);
	}
	if (atol(str[0]) <= 1)
	{
		perror("Error: not enough philo\n");
		return (1);
	}
	return (0);
}
