#include "philo.h"

void init_params(t_params *params, int argc, char **argv) {
    params->number_of_philosophers = atoi(argv[1]);
    params->time_to_die = atoi(argv[2]);
    params->time_to_eat = atoi(argv[3]);
    params->time_to_sleep = atoi(argv[4]);
    params->number_of_meals = (argc == 6) ? atoi(argv[5]) : -1;
    params->start_time = current_timestamp();
    params->someone_died = 0;
}

void init_philosophers_and_forks(t_params *params) {
    int i;

    params->philosophers = malloc(sizeof(t_philosopher) * params->number_of_philosophers);
    params->forks = malloc(sizeof(pthread_mutex_t) * params->number_of_philosophers);

    if (!params->philosophers || !params->forks) {
        perror("Failed to allocate memory");
        exit(1);
    }

    i = 0;
    while (i < params->number_of_philosophers) {
        params->philosophers[i].id = i;
        params->philosophers[i].left_fork = i;
        params->philosophers[i].right_fork = (i + 1) % params->number_of_philosophers;
        params->philosophers[i].last_meal_time = params->start_time;
        params->philosophers[i].meals_eaten = 0;
        params->philosophers[i].params = params;
        if (pthread_mutex_init(&params->forks[i], NULL) != 0) {
            perror("Failed to initialize mutex");
            exit(1);
        }
        i++;
    }
    if (pthread_mutex_init(&params->print_lock, NULL) != 0) {
        perror("Failed to initialize mutex");
        exit(1);
    }
}

void destroy_philosophers_and_forks(t_params *params) {
    int i = 0;
    while (i < params->number_of_philosophers) {
        pthread_mutex_destroy(&params->forks[i]);
        i++;
    }
    pthread_mutex_destroy(&params->print_lock);
    free(params->philosophers);
    free(params->forks);
}
