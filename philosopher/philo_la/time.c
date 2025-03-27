/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 10:43:22 by lhima             #+#    #+#             */
/*   Updated: 2025/03/26 20:05:10 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "Error: gettimeofday\n", 21);
		return (-1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_set_time(long long *value)
{
	*value = ft_get_time();
	if (*value == -1)
	{
		write(2, "Error: gettimeofday\n", 21);
		*value = -1;
		return (-1);
	}
	return (1);
}

void	sleep_fix(long long time)
{
	long long	start;

	start = ft_get_time();
	while (1)
	{
		if ((ft_get_time() - 1) >= time)
			break ;
		usleep(1);
	}
}
