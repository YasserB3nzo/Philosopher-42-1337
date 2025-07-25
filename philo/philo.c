/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybenzidi <ybenzidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 16:43:35 by ybenzidi          #+#    #+#             */
/*   Updated: 2025/07/25 19:02:35 by ybenzidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// pthread_mutex_lock(&fork);
// pthread_mutex_unlock(&fork);
// pthread_mutex_init(&fork, NULL);
// pthread_mutex_destroy(&fork);
// pthread_create(&t1, NULL, routine, NULL);
// pthread_join(t1, NULL);


int main(int ac, char **av)
{
    philo_data *data = get_g_data();
    philosopher philosophers[PHILO_MAX];
    pthread_mutex_t forks[PHILO_MAX];
    checkargument( ac, av);
    init_data(data,av);
    init_philos( philosophers, data, forks);

    // routine 
    
    // timestamp_in_ms X has taken a fork
    // timestamp_in_ms X is eating
    // timestamp_in_ms X is sleeping
    // timestamp_in_ms X is thinking
    // timestamp_in_ms X died
    // destroy(data, philosophers, forks);
    return 0;
}

// number_of_philosophers time_to_die time_to_eat
// time_to_sleep
// [number_of_times_each_philosopher_must_eat]

// n philo == n threads 

// memset, printf, malloc, free, write,  usleep

// gettimeofday:get curent time with microsecond 



// pthread_create : Create a new thread and start execution in the currentr process 

// pthread_join :  It blocks the calling thread until the target thread finishes.

// pthread_mutex_init : To initialize a mutex

// pthread_mutex_destroy : Destroys a mutex when it's no longer needed.

// pthread_mutex_lock : to lock a mutex , if its lready locked the calling thread wait until its availble 

// pthread_mutex_unlock : unlock the thread to make availble for other threads to lock 

// mutex:like a lock used to controll acces to ressources between threads 

// pthread_detach :Detaches a thread, meaning it will automatically 
            //   release resources when it terminates without needing pthread_join().

// fork = mutex 
//  philo = thread 

// thread (philosopher) needs mutexes (forks) to perform the eat action/state.
// Sleep and think are states where the philosopher doesn't need forks.

// 5 philos 

// A thread is the basic unit of execution in a cpu 
//   Each process thread includes instructions 
//     for a cpu to execute in a sequence. 

// process is a running background that is being being executed , it could be a list of intructions are being executed in processeur
//   programm -> process -> thread 
//  multi thread process vs single thread process
//  each thread have hs own registers and stack but it all shared the same space in the memory
// threads can communicate beetwen each other 