/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:12 by lhima             #+#    #+#             */
/*   Updated: 2025/03/25 18:48:20 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* static int check_death(long long end, long long start, long long death)
{
	if(end - start >= death)
		return (0);
	return (1);
} */

static int death_see(t_philo *philo ,int *flag )
{
	printf("%d", philo->status == 1);
	if (philo->status == 1)
	{
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	if(*flag == 0)
		*flag = 1;
	if(philo->eat_count != -1)
		philo->eat_count--;
	return (0);
}
void *do_something(void *t)
{
 	t_philo *philo = (t_philo *)t;
	int		flag;

	flag = 0;
	while (philo->eat_count != 0)
	{
		ft_lock(philo, philo->start_working, flag);
		ft_print(philo, "is eating", \
		philo->start_working, philo->print);
		pthread_mutex_lock(philo->print);
		ft_set_time(&philo->end);
		if(death_see(philo, &flag) == 1)
			return (NULL);
		usleep(philo->time_to_eat * 1000);
		ft_set_time(&philo->end);
		if(death_see(philo, &flag) == 1)
			return (NULL);
		ft_set_time(&philo->start);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		ft_print(philo, "is sleeping",philo->start_working, philo->print);
		usleep(philo->sleep * 1000);
		ft_print(philo, "is thinking",philo->start_working, philo->print);
	}
	return (NULL);
}
