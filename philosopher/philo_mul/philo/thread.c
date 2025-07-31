/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:12 by lhima             #+#    #+#             */
/*   Updated: 2025/03/27 12:21:19 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat(t_philo *philo, int *flag)
{
	if (*flag == 0)
		*flag = 1;
	if (philo->eat_count != -1)
		philo->eat_count--;
}

static int	quit(t_philo *philo)
{
	if (philo->status == 1)
	{
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

void	*do_something(void *t)
{
	t_philo	*philo;
	int		flag;

	philo = (t_philo *)t;
	flag = 0;
	while (philo->eat_count != 0)
	{
		ft_lock(philo, philo->start_working, flag);
		ft_print(philo, "is eating", philo->start_working);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_lock(philo->print);
		ft_set_time(&philo->start);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_lock(philo->print);
		eat(philo, &flag);
		if (quit(philo) == 1)
			return (NULL);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		ft_print(philo, "is sleeping", philo->start_working);
		usleep((philo->sleep * 1000) + 500);
		ft_print(philo, "is thinking", philo->start_working);
	}
	return (NULL);
}
