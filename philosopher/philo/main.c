/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:03 by lhima             #+#    #+#             */
/*   Updated: 2025/03/10 15:28:59 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *do_something(int fork, t_philo *philo)
{
	pthread_mutex_t mutex;

	pthread_mutex_init(&mutex, NULL);
	while(1)

	// fork act as mutex
	/* pthread_mutex_lock(&mutex);
	men_fork(philo);
	pthread_mutex_unlock(&mutex);
	eat(philo); */
	else
		// is thingking

	// is the philosopher eating

	return (NULL);
}

// stampe si sovrappongono mutex

//number_of_philosophers     time_to_die    time_to_eat    time_to_sleep    [number_of_times_each_philosopher_must_eat]
// 5                        800            200            200             		7
// 4                        410            200            200					3
int main(int argc, char **argv)
{
	pthread_mutex_t stop;
	pthread_t *philo;

	if(argc != 6)
	{
		if(argv[1] == NULL)
			perror("Error: no arguments\n");
		else
			perror("Error: wrong number of arguments\n");
		return (1);
	}
	if(checks(argv + 1) == 1)
		return (1);
	philo = malloc(sizeof(pthread_t) * ft_atol(argv[1]));
	pthread_mutex_init(&stop, NULL);
	pthread_create(philo, NULL, &do_something, NULL/*fork and philo*/);
	pthread_join(*philo, NULL); // Wait for the thread to finish
    pthread_mutex_destroy(&stop); // Clean up the mutex
	free(philo);
	return (0);
}
