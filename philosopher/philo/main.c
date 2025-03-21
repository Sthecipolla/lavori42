/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:03 by lhima             #+#    #+#             */
/*   Updated: 2025/03/21 11:58:57 by lhima            ###   ########.fr       */
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
void ft_lock(t_philo *philo, long long start_working, long long end2,int flag)
{
	if (philo->id % 2 == 0 && flag == 0 && philo->id == 0)
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
	}
	else if (philo->id % 2 == 0 && flag == 0)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
	}
	else if (philo->id % 2 != 0 && flag == 0)
	{
		usleep(1000);
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
	}
	else if (philo->id == 0 && flag == 1)
	{
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
	}
	else if (flag == 1)
	{
		pthread_mutex_lock(philo->left_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
		pthread_mutex_lock(&philo->right_fork);
		ft_set_time(&end2);
		ft_print(philo->id, "has taken a fork", end2 - start_working, philo->print);
	}
}
void *do_something(void *t)
{
 	t_philo *philo = (t_philo *)t;
	long	long start;
	long	long end;
	long	long start_working;
	long	long end2;
	int		flag = 0;

	start = 0;
	end = 0;
	ft_set_time(&start_working);
	while (philo->eat_count != 0)
	{
		ft_lock(philo,start_working, end2,flag);
		ft_set_time(&end2);
		ft_print(philo->id, "is eating",end2 - start_working, philo->print);
		usleep(philo->time_to_eat * 1000);
		philo->eat_count--;
		ft_set_time(&end2);
		ft_set_time(&end);
		/* printf("start %lld\n", start - start_working);
		printf("end %lld\n", end - start_working);
		printf("%lld\n", (end - start)); */
		if(((end - start) >= philo->time_to_die) && flag == 1)
		{
			ft_print(philo->id, "died",end2 - start_working, philo->print);
			pthread_mutex_unlock(&philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (NULL);
		}
		else if(flag == 0)
			flag = 1;
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		ft_set_time(&start);
		ft_set_time(&end2);
		ft_print(philo->id, "is sleeping", end2 - start_working, philo->print);
		usleep(philo->sleep * 1000);
		ft_set_time(&end2);
		ft_print(philo->id, "is thinking", end2 - start_working, philo->print);
		if(start == -1 || end == -1)
			return (NULL);
	}
	return (NULL);
}

//number_of_philosophers     time_to_die    time_to_eat    time_to_sleep    [number_of_times_each_philosopher_must_eat]
// 5                        800            200            200             		7
// 4                        410            200            200					3


/// aggiungere mutex per stampare per bene
int main(int argc, char **argv)
{
	pthread_t *thread;
	t_philo *philos;
	pthread_mutex_t print;
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
	pthread_mutex_init(&print, NULL);
	fill_philo(philos, argv, &print);
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
	pthread_mutex_destroy(&print);
	free(philos);
	free(thread);
	return (0);
}
