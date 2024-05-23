#include "philo.h"

void print_status(t_params *params, int id, const char *status) {
    pthread_mutex_lock(&params->print_lock);
    if (!params->someone_died) {
        printf("%lld %d %s\n", current_timestamp() - params->start_time, id + 1, status);
    }
    pthread_mutex_unlock(&params->print_lock);
}

void eat(t_philosopher *philo) {
    t_params *params = philo->params;
    pthread_mutex_lock(&params->forks[philo->left_fork]);
    print_status(params, philo->id, "has taken a fork");
    pthread_mutex_lock(&params->forks[philo->right_fork]);
    print_status(params, philo->id, "has taken a fork");
    print_status(params, philo->id, "is eating");
    philo->last_meal_time = current_timestamp();
    usleep(params->time_to_eat * 1000);
    philo->meals_eaten++;
    pthread_mutex_unlock(&params->forks[philo->right_fork]);
    pthread_mutex_unlock(&params->forks[philo->left_fork]);
}

void *philosopher_routine(void *arg) {
    t_philosopher *philo = (t_philosopher *)arg;
    t_params *params = philo->params;

    while (!params->someone_died) {
        print_status(params, philo->id, "is thinking");
        eat(philo);
        print_status(params, philo->id, "is sleeping");
        usleep(params->time_to_sleep * 1000);
    }
    return NULL;
}

void check_death(t_params *params) {
    int i;
    while (!params->someone_died) {
        i = 0;
        while (i < params->number_of_philosophers) {
            if (current_timestamp() - params->philosophers[i].last_meal_time > params->time_to_die) {
                print_status(params, i, "died");
                params->someone_died = 1;
                break;
            }
            i++;
        }
        usleep(1000);
    }
}
