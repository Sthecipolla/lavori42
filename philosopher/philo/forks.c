/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 12:37:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/21 13:05:19 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	sleep_a_little(t_philo *philo, long long start_working, \
							long long end2)
{
	usleep(1000);
	pthread_mutex_lock(philo->left_fork);
	ft_set_time(&end2);
	ft_print(philo->id, "has taken a fork", \
	end2 - start_working, philo->print);
	pthread_mutex_lock(&philo->right_fork);
	ft_set_time(&end2);
	ft_print(philo->id, "has taken a fork", \
	end2 - start_working, philo->print);
}

static void	first_lock(t_philo *philo, long long start_working, \
						long long end2, int flag)
{
	if (philo->id % 2 == 0 && flag == 0 && philo->id == 0)
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
	}
	else if (philo->id % 2 == 0 && flag == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
	}
	else if (philo->id % 2 != 0 && flag == 0)
		sleep_a_little(philo, start_working, end2);
}

void	ft_lock(t_philo *philo, long long start_working, \
				long long end2, int flag)
{
	if (flag == 0)
		first_lock(philo, start_working, end2, flag);
	else if (philo->id == 0 && flag == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", \
		end2 - start_working, philo->print);
	}
}
