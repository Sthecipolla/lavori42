/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:03 by lhima             #+#    #+#             */
/*   Updated: 2025/03/25 11:46:31 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// "2" entrambe sono prese e pront a mangiare
// "1" disponibili

int lets_see(int argc, char **argv, pthread_t **thread, t_philo **philos)
{
	if(argc != 6 && argc != 5)
	{
		if(argv[1] == NULL)
			perror("Error: no arguments\n");
		else
			perror("Error: wrong number of arguments\n");
		return (1);
	}
	if(checks(argv + 1) == 1)
		return (1);
	*philos =  malloc(sizeof(t_philo) * ft_atol(argv[1]));
	if(philos == NULL)
	{
		perror("Error: malloc\n");
		return (1);
	}
	*thread = malloc(sizeof(pthread_t) * ft_atol(argv[1]));
	if(thread == NULL)
	{
		free(*philos);
		perror("Error: malloc\n");
		return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	pthread_t *thread;
	t_philo *philos;
	pthread_mutex_t print;
	pthread_t *death;
	long long time;
	int i;

	if (lets_see(argc, argv, &thread, &philos))
		return (1);
	pthread_mutex_init(&print, NULL);
	ft_set_time(&time);
	fill_philo(philos, argv, &print, time);
	i = -1;
	while(++i < ft_atol(argv[1]))
		pthread_create(&thread[i], NULL, &do_something,(void *) &philos[i]);
	i = -1;
	death = malloc(sizeof(pthread_t));
	pthread_create(death, NULL, &is_dead,(void *) philos);
	pthread_join(*death, NULL);
	while(++i < ft_atol(argv[1]))
		pthread_join(thread[i], NULL);
	i = -1;
	while(++i < ft_atol(argv[1]))
		pthread_mutex_destroy(&philos[i].right_fork);
	pthread_mutex_destroy(&print);
	free(death);
	free(philos);
	free(thread);
	return (0);
}
