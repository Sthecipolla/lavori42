/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 11:24:55 by lhima             #+#    #+#             */
/*   Updated: 2025/03/24 14:15:13 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	int				tot_filo;
	long long		sleep;
	long long		time_to_die;
	long long		eat_count;
	long long		time_to_eat;
	long long		start;
	long long		end;
	int				status;
	long long		*start_working;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	pthread_mutex_t	*print;
}					t_philo;

int			checks(char **str);
long long	ft_atol(const char *nptr);
void		fill_philo(t_philo *philo, char **argv, pthread_mutex_t *print, long long *time);
void		print_philo(t_philo *philo);
void		ft_print(t_philo *philo, char *str, long long time, pthread_mutex_t *print);
void		ft_lock(t_philo *philo, long long start_working, int flag);
int			ft_set_time(long long *value);
void		*is_dead(void *p);



# endif
