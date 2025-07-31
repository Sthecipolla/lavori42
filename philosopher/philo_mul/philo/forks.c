/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:37:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/27 12:09:09 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_a_little(t_philo *philo, long long start_working)
{
	usleep(100);
	pthread_mutex_lock(philo->left_fork);
	ft_print(philo, "has taken a fork", start_working);
	pthread_mutex_lock(&philo->right_fork);
	ft_print(philo, "has taken a fork", start_working);
}

static void	first_lock(t_philo *philo, long long start_working, int flag)
{
	if (philo->id % 2 == 0 && flag == 0 && philo->id == 0)
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_print(philo, "has taken a fork", start_working);
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork", start_working);
	}
	else if (philo->id % 2 == 0 && flag == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork", start_working);
		pthread_mutex_lock(&philo->right_fork);
		ft_print(philo, "has taken a fork", start_working);
	}
	else if (philo->id % 2 != 0 && flag == 0)
		sleep_a_little(philo, start_working);
}

void	ft_lock(t_philo *philo, long long start_working, int flag)
{
	if (flag == 0)
		first_lock(philo, start_working, flag);
	else if (philo->id == 0 && flag == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_print(philo, "has taken a fork", start_working);
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork", start_working);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_print(philo, "has taken a fork", start_working);
		pthread_mutex_lock(&philo->right_fork);
		ft_print(philo, "has taken a fork", start_working);
	}
}
