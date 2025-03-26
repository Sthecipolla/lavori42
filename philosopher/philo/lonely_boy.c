/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lonely_boy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 17:05:01 by lhima             #+#    #+#             */
/*   Updated: 2025/03/26 19:10:27 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*lonely(void *t)
{
	t_philo *philo;

	philo = (t_philo *) t;
	printf("%lld %d is taken a fork\n", ft_get_time() \
	- philo->start_working, philo->id + 1);
	usleep(1000 * philo->time_to_die);
	printf("%lld %d died\n", philo->time_to_die, philo->id + 1);
	return (NULL);
}
