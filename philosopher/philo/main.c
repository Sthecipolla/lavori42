/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:03 by lhima             #+#    #+#             */
/*   Updated: 2025/03/21 16:35:40 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// "2" entrambe sono prese e pront a mangiare
// "1" disponibili

long long ft_get_time(void)
{
	struct timeval time;

	if(gettimeofday(&time, NULL) == -1)
	{
		perror("Error: gettimeofday\n");
		return (-1);
	}
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int ft_set_time(long long *value)
{
	*value = ft_get_time();
	if(*value == -1)
	{
		perror("Error: gettimeofday\n");
		*value = -1;
		return -1;
	}
	return 1;
}

void *do_something(void *t)
{
 	t_philo *philo = (t_philo *)t;
	long	long start_working;
	long	long action;
	int		flag = 0;

	ft_set_time(&start_working);
	while (philo->eat_count != 0)
	{
		ft_lock(philo,start_working, action,flag);
		ft_set_time(&action);
		ft_print(philo->id, "is eating", \
		action - start_working, philo->print);
		usleep(philo->time_to_eat * 1000);
		philo->eat_count--;
		ft_set_time(&action);
		ft_set_time(&philo->end);
		/* printf("start %lld\n", start - start_working);
		printf("end %lld\n", end - start_working);
		printf("%lld\n", (end - start)); */
		if(((philo->end - philo->start) >= philo->time_to_die) && flag == 1)
		{
			ft_print(philo->id, "died", \
			action - start_working, philo->print);
			philo->status = 1;
			pthread_mutex_unlock(&philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (NULL);
		}
		else if(flag == 0)
			flag = 1;
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		ft_set_time(&philo->start);
		ft_set_time(&action);
		ft_print(philo->id, "is sleeping", action - start_working, philo->print);
		usleep(philo->sleep * 1000);
		ft_set_time(&action);
		ft_print(philo->id, "is thinking", action - start_working, philo->print);
	}
	return (NULL);
}

// da aggiustare ora mi da segfault
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
	pthread_mutex_t murder;
	char *str;
	int i;

	if (lets_see(argc, argv, &thread, &philos))
		return (1);
	pthread_mutex_init(&print, NULL);
	pthread_mutex_init(&murder, NULL);
	fill_philo(philos, argv, &print, murder);
	i = -1;
	while(++i < ft_atol(argv[1]))
		pthread_create(&thread[i], NULL, &do_something, &philos[i]);
	i = -1;
	murder = malloc(sizeof(pthread_t));
	pthread_create(&murder, NULL, &is_dead, philos);
	pthread_join(thread[i], NULL);
	while(++i < ft_atol(argv[1]))
		pthread_join(thread[i], NULL);
	i = -1;
	while(++i < ft_atol(argv[1]))
		pthread_mutex_destroy(&philos[i].right_fork);
	pthread_mutex_destroy(&print);
	free(philos);
	free(thread);
	return (0);
}
