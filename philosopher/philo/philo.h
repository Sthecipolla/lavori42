# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>


// salvarsi il mutex di quello a sinistra
typedef struct s_philo
{
	int id;
	int tot_filo;
	long long sleep;
	long long time_to_die;
	long long eat;
	long long time_to_eat;
	long long think;
	int *left_fork;
	int right_fork;
	int status;
}					t_philo;


int			checks(char **str);
long long	ft_atol(const char *nptr);
void		fill_philo(t_philo *philo, char **argv);
void		print_philo(t_philo *philo);


# endif














/* typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				eat_count;
	long long		last_eat;
	pthread_t		thread;
	struct s_data	*data;
}					t_philo;
 */
