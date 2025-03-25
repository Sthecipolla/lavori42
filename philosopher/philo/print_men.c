/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_men.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:04 by lhima             #+#    #+#             */
/*   Updated: 2025/03/25 13:02:36 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_print(t_philo *philo, char *str, long long time, pthread_mutex_t *print)
{
	long	long action;
	int id;

	usleep(7);
	pthread_mutex_lock(print);
	id = philo->id + 1;
	if(philo->status == 1)
	{
		pthread_mutex_unlock(print);
		return ;
	}
	ft_set_time(&action);
	time = action - time;
	printf("%lld %d %s\n", time, id, str);
	pthread_mutex_unlock(print);
}

void	print_philo(t_philo *philo)
{
	printf("philo %d\n", philo->id);
	printf("tot_filo %d\n", philo->tot_filo);
	printf("time_to_die %lld\n", philo->time_to_die);
	printf("eat count %lld\n", philo->eat_count);
	printf("time_to_eat %lld\n", philo->time_to_eat);
	printf("sleep %lld\n", philo->sleep);
	printf("-------------------------\n");
}
