#include <stdio.h>      // printf, perror
#include <pthread.h>    // pthread_create, pthread_join, pthread_t
#include <unistd.h>     // fork, getpid
#include <sys/types.h>  // pid_t
#include <sys/time.h>

pthread_mutex_t mutex;
// int counter = 0;

void *safe_increment() {
    pthread_mutex_lock(&mutex);
    // counter++;  // Protected critical section
    pthread_mutex_unlock(&mutex);
    return NULL;
}

void *routine(void *arg)
{
    // safe_increment();
    struct timeval tv;
    // (void)arg; // Avoid unused parameter warning
    if(arg != NULL) {
        printf(" Thread took argument \n");
    }
    else {
        printf(" Thread took no argument \n");
    }
    gettimeofday(&tv, NULL);
    long time = tv.tv_sec * 1000 + tv.tv_usec / 1000; // Convert to milliseconds
    printf("First Thread time is %ld \n", time);
    return NULL;
}

void *routine2(void *arg)
{
    // (void)arg; // Avoid unused parameter warning
    if(arg != NULL) {
        printf("Second Thread took argument \n");
    }
    else {
        printf("Second Thread took no argument \n");
    }
    return NULL;
}

// fork() duplicate the current process
// pid == 0 means the current process is the child process

int main()
{
    pthread_t t1; // Declare a thread variable
    pthread_t t2;
    // pthread_attr_t attr; 

    // pid_t pid = fork();
    // if (pid < 0)
    // {
    //     perror("Fork failed");
    //     return 1; // Exit if fork fails
    // }
    pthread_mutex_init(&mutex, NULL);
    pthread_create(&t1, NULL, routine, NULL);
    pthread_create(&t2, NULL, routine, "NULL");
    pthread_join(t1, NULL); // Wait for the thread to finish
    pthread_join(t2, NULL);
    pthread_mutex_destroy(&mutex); // Destroy the mutex
    // int pthread_create(pthread_t *restrict thread, const pthread_attr_t *restrict attr, void *(*start_routine)(void *), void *restrict arg);
    return 0;
}

// pthread_t t1; // hold a thread identifier so the os identify the thread


// Typical pthread_t structure (varies by system)
// typedef struct {
//     unsigned long int thread_id;      Unique thread identifier
//     void *stack_pointer;              Current stack location
//     int state;                        Thread state (running, blocked, etc.)
//     void *return_value;               Value returned by thread function
//     pthread_attr_t attributes;        Thread attributes
//     // Other system-specific fields...
// } pthread_t;