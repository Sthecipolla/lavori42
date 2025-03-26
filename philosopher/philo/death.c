/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:29:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/26 18:52:39 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void set_all_one(t_philo *philos, int j)
{
	int i;

	i = -1;
	printf("%lld %d died\n", ft_get_time() - philos[j].start_working, philos[j].id + 1);
	while(++i < philos[0].tot_filo)
		philos[i].status = 1;
	pthread_mutex_unlock(philos[0].print);

}

void *is_dead(void *p)
{
	t_philo *philos = (t_philo *)p;
	int i;
	int j;
	while (1)
	{
		usleep(10);
		pthread_mutex_lock(philos[0].print);
		j = 0;
		i = -1;
		while(++i < philos[0].tot_filo)
		{
			if (philos[i].eat_count == 0)
				j++;
			if (ft_get_time() - philos[i].start >= philos[i].time_to_die)
				return (set_all_one(philos, i), NULL);
		}
		if(j == philos[0].tot_filo)
			break;
		pthread_mutex_unlock(philos[0].print);
	}
	pthread_mutex_unlock(philos[0].print);
	return (NULL);
}
