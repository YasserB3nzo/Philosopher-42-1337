/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:42:00 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/25 20:04:40 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
#define PHILO_H 

#include <pthread.h>   
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <limits.h>
#include <sys/types.h>

#ifndef PHILO_MAX
# define PHILO_MAX 200
#endif

typedef struct data
{
    int number_of_philo;
    unsigned long time_to_sleep;
    unsigned long time_to_die; //milliseconds 
    unsigned long time_to_eat;
    unsigned long number_of_times_each_philosopher_must_eat;
    unsigned long start_time;
    int dead_flag;
    pthread_mutex_t *forks;        // array of fork mutexes
    pthread_mutex_t write_lock;    // print mutex
    pthread_mutex_t dead_lock;     // death flag mutex
    pthread_mutex_t meal_lock;     // meal counting mutex
    pthread_mutex_t log; // printf 
} philo_data;

typedef struct philo 
{
    pthread_t thread;              // thread ID
    int philo_id;                  // philosopher ID (1, 2, 3...)
    int meal_counter;              // number of meals eaten
    unsigned long last_meal_time;  // timestamp of last meal
    philo_data *data;              // pointer to shared data structure
    pthread_mutex_t *left_fork;    // pointer to left fork mutex
    pthread_mutex_t *right_fork;   // pointer to right fork mutex
} philosopher;


# define PHILO_MAX_COUNT 200 


void    checkargument(int ac, char **av);
void    error_message();
long	ft_atoi(const char *str);
void	*get_g_data();
long	timestamp_in_ms(void);
void	init_data(philo_data *data, char **av);
void	*routine();
void	init_philos(philosopher *philosophers, philo_data *data,pthread_mutex_t *forks);

void	destroy(philo_data *data, philosopher *philosophers, pthread_mutex_t *forks);



#endif

// 2 diffrents structs because some data needs to b shared upp


