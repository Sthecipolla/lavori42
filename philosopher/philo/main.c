/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:03 by lhima             #+#    #+#             */
/*   Updated: 2025/03/13 16:41:31 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// "2" entrambe sono prese e pront a mangiare
// "1" disponibili


void set_eat(t_philo *philo)
{
	philo->status = 1;
	*philo->left_fork = 0;
	philo->right_fork = 0;
	philo->eat_count--;
}
void set_status_wait(t_philo *philo)
{

	philo->status = 0;
	*philo->left_fork = 1;
	philo->right_fork = 1;
}

void *do_something(void *t)
{
 	t_philo *philo = (t_philo *)t;
	pthread_mutex_t mutex;

	mutex = philo->mutex;
	while(philo->eat_count != 0)
	{
		pthread_mutex_lock(&mutex);
		print_philo(philo);
		if(*philo->left_fork == 1 && philo->right_fork == 1)
		{
			pthread_mutex_unlock(&mutex);
			set_eat(philo);
			usleep(philo->time_to_eat);
			set_status_wait(philo);
		}
		else
		{
			pthread_mutex_unlock(&mutex);
			philo->status = 2;
		}
		if (philo->status == 1)
		{
			usleep(300);
		}
		else if (philo->status == 2)
			printf("philo %d is thinking\n", philo->id);

	}

	return (NULL);
}


//number_of_philosophers     time_to_die    time_to_eat    time_to_sleep    [number_of_times_each_philosopher_must_eat]
// 5                        800            200            200             		7
// 4                        410            200            200					3
int main(int argc, char **argv)
{
	pthread_t *thread;
	t_philo *philos;
	int i;

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
	philos =  malloc(sizeof(t_philo) * ft_atol(argv[1]));
	if(philos == NULL)
	{
		perror("Error: malloc\n");
		return (1);
	}
	thread = malloc(sizeof(pthread_t) * ft_atol(argv[1]));
	if(thread == NULL)
	{
		free(philos);
		perror("Error: malloc\n");
		return (1);
	}
	fill_philo(philos, argv, &mutex);
	i = -1;
	while(++i < ft_atol(argv[1]))
		pthread_create(&thread[i], NULL, &do_something, &philos[i]);
	i = -1;
	while(++i < ft_atol(argv[1]))
	{
		pthread_join(thread[i], NULL);
	}
	i = -1;
	while(++i < ft_atol(argv[1]))
	{
		pthread_mutex_destroy(&philos[i].right_fork);
	}
	free(philos);
	free(thread);
	return (0);
}
