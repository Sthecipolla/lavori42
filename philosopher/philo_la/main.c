/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 12:00:03 by lhima             #+#    #+#             */
/*   Updated: 2025/03/26 20:07:54 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_philo *philos, char **argv)
{
	pthread_t	*thread;

	thread = malloc(sizeof(pthread_t) * ft_atol(argv[1]));
	pthread_create(&thread[0], NULL, &lonely, (void *)&philos[0]);
	pthread_join(thread[0], NULL);
	free(philos);
	free(thread);
	return (0);
}

static void	create(t_philo *philos, pthread_t *thread, char **argv)
{
	int	i;

	i = -1;
	while (++i < ft_atol(argv[1]))
		if (philos[i].id % 2 == 0)
			pthread_create(&thread[i], NULL, &do_something, (void *)&philos[i]);
	i = -1;
	while (++i < ft_atol(argv[1]))
		if (philos[i].id % 2 != 0)
			pthread_create(&thread[i], NULL, &do_something, (void *)&philos[i]);
}

int	lets_see(int argc, char **argv, pthread_t **thread, t_philo **philos)
{
	if (argc != 6 && argc != 5)
	{
		if (argv[1] == NULL)
			write(2, "Error: no arguments\n", 20);
		else
			write(2, "Error: wrong number of arguments\n", 34);
		return (1);
	}
	if (checks(argv + 1) == 1)
		return (1);
	*philos = malloc(sizeof(t_philo) * ft_atol(argv[1]));
	if (philos == NULL)
	{
		write(2, "Error: malloc\n", 14);
		return (1);
	}
	*thread = malloc(sizeof(pthread_t) * ft_atol(argv[1]));
	if (thread == NULL)
	{
		free(*philos);
		write(2, "Error: malloc\n", 14);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	pthread_t		*thread;
	t_philo			*philos;
	pthread_mutex_t	print;
	pthread_t		*death;
	int				i;

	if (lets_see(argc, argv, &thread, &philos))
		return (1);
	pthread_mutex_init(&print, NULL);
	fill_philo(philos, argv, &print, ft_get_time());
	if (atol(argv[1]) == 1)
		return (one_philo(philos, argv));
	i = -1;
	create(philos, thread, argv);
	death = malloc(sizeof(pthread_t));
	pthread_create(death, NULL, &is_dead, (void *)philos);
	pthread_join(*death, NULL);
	while (++i < ft_atol(argv[1]))
		pthread_join(thread[i], NULL);
	i = -1;
	while (++i < ft_atol(argv[1]))
		pthread_mutex_destroy(&philos[i].right_fork);
	pthread_mutex_destroy(&print);
	free(thread);
	return (free(death), free(philos), 0);
}
