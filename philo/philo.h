/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:42:00 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/27 22:20:46 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <unistd.h>

# ifndef PHILO_MAX
#  define PHILO_MAX 200
# endif

typedef struct data
{
	int				number_of_philo;
	unsigned long	time_to_sleep;
	unsigned long	time_to_die;
	unsigned long	time_to_eat;
	unsigned long	meals;
	unsigned long	start_time;
	int				dead_flag;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
}					philo_data;

typedef struct philo
{
	pthread_t		thread;
	int				philo_id;
	int				meal_counter;
	unsigned long	last_meal_time;
	philo_data		*data;
	int				one_dead_flag;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					philosopher;

# define PHILO_MAX_COUNT 200

int					checkargument(int ac, char **av);
int					error_message(void);
long				ft_atoi(const char *str);
void				*get_g_data(void);
long				timestamp_in_ms(void);
void				init_data(philo_data *data, char **av);
void				init_philos(philosopher *philosophers, philo_data *data,
						pthread_mutex_t *forks);
void				*monitor(void *arg);
void				destroy(philo_data *data, philosopher *philosophers,
						pthread_mutex_t *forks);
int					one_casephilo(philo_data *data, pthread_mutex_t *forks);
void				*philosopher_routine(void *arg);
void				init_threads(philosopher *philosophers, philo_data *data);
void				eat(philosopher *philo);
void				think(philosopher *philo);
void				dream(philosopher *philo);
void				ft_usleep(unsigned long milliseconds);
void				print_message(char *str, philosopher *philo, int id);
int					dead_flag_check(philosopher *philo);
int					philosopher_dead(philosopher *philo);
int					check_if_dead(philosopher *philos);
int					check_if_all_ate(philosopher *philos);
size_t				get_current_time(void);
int					check_all_if_dead(philosopher *philo);

#endif
