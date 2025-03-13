/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_men.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:45:04 by lhima             #+#    #+#             */
/*   Updated: 2025/03/13 15:35:29 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* void print_men()
{
	printf("bella ragazzi e benvenuti in questo nuovo video\n");
} */

void	print_philo(t_philo *philo)
{
	/* write(1,"philo ", 6);
	int i;

	i = philo->id + '0';
	write(1, &i , 1);
	write(1,"\n", 1); */
	printf("philo %d\n", philo->id);
	printf("tot_filo %d\n", philo->tot_filo);
	printf("time_to_die %lld\n", philo->time_to_die);
	printf("eat %lld\n", philo->eat);
	printf("time_to_eat %lld\n", philo->time_to_eat);
	printf("sleep %lld\n", philo->sleep);
	printf("think %lld\n", philo->think);
	printf("left_fork %d\n", *philo->left_fork);
	printf("right_fork %d\n", philo->right_fork);
	printf("status %d\n", philo->status);
	printf("-------------------------\n");
}
