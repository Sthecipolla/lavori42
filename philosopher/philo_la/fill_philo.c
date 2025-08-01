/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/25 16:43:33 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
1 number_of_philosophers
2 time_to_die
3 time_to_eat
4 time_to_sleep
5 [number_of_times_each_philosopher_must_eat]
*/
void	fill_philo(t_philo *philo, char **argv, pthread_mutex_t *print,
		long long time)
{
	int	i;

	i = -1;
	while (atol(argv[1]) > ++i)
	{
		philo[i].id = i;
		philo[i].tot_filo = (int)atol(argv[1]);
		philo[i].time_to_die = atol(argv[2]);
		if (argv[5] == NULL)
			philo[i].eat_count = -1;
		else
			philo[i].eat_count = atol(argv[5]);
		philo[i].sleep = atol(argv[4]);
		philo[i].time_to_eat = atol(argv[3]);
		philo[i].print = print;
		philo[i].status = 0;
		philo[i].start_working = time;
		if (i == 0)
			philo[i].left_fork = &philo[atol(argv[1]) - 1].right_fork;
		else
			philo[i].left_fork = &philo[i - 1].right_fork;
		pthread_mutex_init(&philo[i].right_fork, NULL);
		philo[i].start = time;
		philo[i].end = 0;
	}
}
