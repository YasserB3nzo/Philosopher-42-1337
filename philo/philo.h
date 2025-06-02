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
    unsigned long time_to_die;
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


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <pthread.h>


#endif

// 2 diffrents structs because some data needs to b shared upp


