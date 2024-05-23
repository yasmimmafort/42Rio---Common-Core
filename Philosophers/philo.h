#ifndef PHILO_H
#define PHILO_H

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_philosopher {
    int id;
    int left_fork;
    int right_fork;
    long long last_meal_time;
    int meals_eaten;
    pthread_t thread;
    struct s_params *params;
} t_philosopher;

typedef struct s_params {
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_meals;
    long long start_time;
    pthread_mutex_t *forks;
    pthread_mutex_t print_lock;
    t_philosopher *philosophers;
    int someone_died;
} t_params;

long long current_timestamp(void);
void print_status(t_params *params, int id, const char *status);
void *philosopher_routine(void *arg);
void eat(t_philosopher *philo);
void check_death(t_params *params);
void init_params(t_params *params, int argc, char **argv);
void init_philosophers_and_forks(t_params *params);
void destroy_philosophers_and_forks(t_params *params);

#endif
