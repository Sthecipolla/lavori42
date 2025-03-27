/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_men.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:04 by lhima             #+#    #+#             */
/*   Updated: 2025/03/26 17:02:53 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_print(t_philo *philo, char *str, long long time)
{
	usleep(7);
	pthread_mutex_lock(philo->print);
	if (philo->status == 1)
	{
		pthread_mutex_unlock(philo->print);
		return (1);
	}
	ft_set_time(&philo->end);
	time = philo->end - time;
	printf("%lld %d %s\n", time, philo->id + 1, str);
	pthread_mutex_unlock(philo->print);
	return (0);
}
