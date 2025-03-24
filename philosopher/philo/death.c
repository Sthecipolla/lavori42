/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/24 11:57:11 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

//mutex per la morte e fai exit del programma

static void set_all_one(t_philo *philos)
{
	int i;

	i = -1;
	while(++i < philos[0].tot_filo)
		philos[i].status = 1;
}

void *is_dead(void *p)
{
	t_philo *philos = (t_philo *)p;
	int i;
	int j;

	while (1)
	{
		pthread_mutex_lock(philos[0].print);
		j = 0;
		i = -1;
		while(++i < philos[0].tot_filo)
		{
			if (philos[i].eat_count == 0)
				j++;
			if (philos[i].status == 1)
				set_all_one(philos);
		}
		if(philos[0].status == 1)
			break;
		if(j == philos[0].tot_filo)
			break;
		pthread_mutex_unlock(philos[0].print);
		usleep(10);
	}
	pthread_mutex_unlock(philos[0].print);
	return (NULL);
}
