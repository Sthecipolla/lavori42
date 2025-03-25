/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:12 by lhima             #+#    #+#             */
/*   Updated: 2025/03/25 12:33:06 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


/* static int	check_start(long long end, long long start, long long death, int flag)
{
	if(flag == 0 && end - start >= death)
		return (0);
	return (1);
} */

static int check_death(long long end, long long start, long long death, int flag)
{
	if(flag == 0 && end - start >= death)
		return (0);
	if(flag == 1 && end - start >= death)
		return (0);
	return (1);
}

static int death_see(t_philo *philo,int *flag)
{
	if (philo->status == 1)
	{
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	if (check_death(philo->end, philo->start, philo->time_to_die, *flag) == 0 && \
		check_death(philo->end, philo->start_working, philo->time_to_die, *flag) == 0)
	{
		ft_set_time(&philo->end);
		printf("%lld %d died\n", philo->end - philo->start_working, philo->id);
		philo->status = 1;
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	else if(*flag == 0)
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
		usleep(philo->time_to_eat * 1000);
		ft_set_time(&philo->end);
		pthread_mutex_lock(philo->print);
		if(death_see(philo, &flag) == 1)
			return (NULL);
		pthread_mutex_unlock(philo->print);
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		ft_set_time(&philo->start);
		ft_print(philo, "is sleeping",philo->start_working, philo->print);
		usleep(philo->sleep * 1000);
		ft_print(philo, "is thinking",philo->start_working, philo->print);
	}
	return (NULL);
}
