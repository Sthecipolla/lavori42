/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_men.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:04 by lhima             #+#    #+#             */
/*   Updated: 2025/03/18 13:49:20 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void print_men()
{
	printf("bella ragazzi e benvenuti in questo nuovo video\n");
} */

void ft_print(int i, char *str, long long time, pthread_mutex_t *print)
{
	pthread_mutex_lock(print);
	printf("%lld %d %s\n", time, i, str);
	pthread_mutex_unlock(print);
}
/* {

	printf("%lld %d %s", time, i, str);
} */

void	print_philo(t_philo *philo)
{
	printf("philo %d\n", philo->id);
	printf("tot_filo %d\n", philo->tot_filo);
	printf("time_to_die %lld\n", philo->time_to_die);
	printf("eat count %lld\n", philo->eat_count);
	printf("time_to_eat %lld\n", philo->time_to_eat);
	printf("sleep %lld\n", philo->sleep);
	printf("think %lld\n", philo->think);
	printf("-------------------------\n");
}
/*
time stamp


*/
