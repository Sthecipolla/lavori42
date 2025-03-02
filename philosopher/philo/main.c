#include "philo.h"

void *do_something(pthread_mutex_t stop)
{
	pthread_mutex_lock(&stop);
	printf("Hello, world!\n");
	pthread_mutex_unlock(&stop);

	return (NULL);
}

int main(int argc, char **argv)
{
	if(argc == 5)
	{
		if(argv[1] == NULL)
			printf("Error: no arguments\n");
		else
			printf("Error: wrong number of arguments\n");
		return (1);
	}
	pthread_mutex_t stop;
	pthread_t philo;

	pthread_mutex_init(&stop, NULL);
	pthread_create(&philo, NULL, &do_something, &stop);
	return (0);
}