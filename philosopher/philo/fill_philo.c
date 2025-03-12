#include "philo.h"

void fill_philo(t_philo *philo, char argv)
{
	int i;

	i = -1
	while (number_of_philo > ++i)
	{
		philo[i].id = i;
		philo[i].tot_filo =(int) atol(argv[1]);
		philo[i].time_to_die = atol(argv[2]);
		philo[i].eat = atol(argv[3]);
		philo[i].sleep = atol(argv[4]);
		philo[i].think = 0;
		if(i == 0)
			philo[i].left_fork = &philo[number_of_philo - 1].right_fork;
		else
			philo[i].left_fork = &philo[i - 1].right_fork;
		philo[i].right_fork = 1;
		philo[i].status = 0;
	}	
}
