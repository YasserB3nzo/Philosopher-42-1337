/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:42:00 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/06/01 22:55:12 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PHILO_H
#define PHILO_H 



typedef struct data
{
    int number_of_philo ;
    unsigned long time_to_sleep;
    unsigned long time_to_die; //milliseconds 
    unsigned long time_to_eat;
    unsigned long number_of_times_each_philosopher_must_eat;
 //     - array of fork mutexes
 //     - print mutex
 //     - death flag
 //     - start time

} philo_data;

typedef struct philo 
{
    int philo_id;
    int meal_counter;
    int last_meal_time;
    /*
    - philosopher ID (0, 1, 2, 3...)
    - thread ID
    - meal count 
    - last meal timestamp
    - pointer to shared data structure
    - pointer to left fork mutex
    - pointer to right fork mutex    
    */

    
} philosopher;

// // typedef struct s_var{
// // 	int					time2die;
// // 	int					time2eat;
// // 	int					time2sleep;
// 	int					is_dead;
// // 	int					max_meals;
// 	unsigned long		start_time;
// 	int					count_philos;
// 	philosopher			*philos;
// 	pthread_mutex_t		*forks;
// 	pthread_mutex_t		printing;
// 	pthread_mutex_t		meal;
// 	pthread_mutex_t		dead;
// // }	t_var;


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>
#include <limits.h>

# define PHILO_MAX_COUNT 200 

#include"./printf/ft_printf.h"

void checkargument(int ac, char **av);
void error_message();
long	ft_atoi(const char *str);




#endif

// 2 diffrents structs because some data needs to b shared upp


