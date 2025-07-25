#include "../philo.h"

long timestamp_in_ms(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    // printf("%ld\n", (tv.tv_sec * 1000) + (tv.tv_usec / 1000));
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
void error_message()
{
    write(2, "Error: Invalid arguments\n", 24);
    exit(EXIT_FAILURE);
}
void destroy(philo_data *data, philosopher *philosophers, pthread_mutex_t *forks)
{
    free(data->forks);
    pthread_mutex_destroy(&data->write_lock);
    pthread_mutex_destroy(&data->dead_lock);
    pthread_mutex_destroy(&data->meal_lock);
}


// pthread_mutex_lock(&fork);
// pthread_mutex_unlock(&fork);
// pthread_mutex_init(&fork, NULL);
// pthread_mutex_destroy(&fork);
// pthread_create(&t1, NULL, routine, NULL);
// pthread_join(t1, NULL);