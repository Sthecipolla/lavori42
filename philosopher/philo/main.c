#include "philo.h"

void *do_something(pthread_mutex_t stop)
{
	pthread_mutex_lock(&stop);
	printf("Hello, world!\n");
	pthread_mutex_unlock(&stop);

	return (NULL);
}


//number_of_philosophers     time_to_die    time_to_eat    time_to_sleep    [number_of_times_each_philosopher_must_eat]
// 5                        800            200            200             		7
// 4                        410            200            200					3
int main(int argc, char **argv)
{
	pthread_mutex_t stop;
	pthread_t philo;

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
	pthread_mutex_init(&stop, NULL);
	pthread_create(&philo, NULL, &do_something, &stop);
	return (0);
}