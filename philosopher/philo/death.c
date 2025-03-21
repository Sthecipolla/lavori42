/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/21 16:41:55 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//mutex per la morte e fai exit del programma

void *is_dead(void *p)
{
	t_philo *philos = (t_philo *)p;
	int i;
	int j;

	while (1)
	{
		j = 0;
		i = -1;
		while(philos[++i])
		{
			if(eat->eat_count == 0)
				j++;
			if(philos[i]-> status == 1)
			{
				printf("%d died\n", philos[i]->id);
				exit(0);
			}
		}
		if(j = philos->tot_filo)
			return (NULL);
	}
	return (NULL);
}
