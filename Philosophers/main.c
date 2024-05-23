#include "philo.h"

int main(int argc, char **argv) {
    t_params params;
    int i;

    if (argc != 5 && argc != 6) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n", argv[0]);
        return 1;
    }

    init_params(&params, argc, argv);
    init_philosophers_and_forks(&params);

    i = 0;
    while (i < params.number_of_philosophers) {
        if (pthread_create(&params.philosophers[i].thread, NULL, philosopher_routine, &params.philosophers[i]) != 0) {
            perror("Failed to create thread");
            return 1;
        }
        i++;
    }

    check_death(&params);

    i = 0;
    while (i < params.number_of_philosophers) {
        if (pthread_join(params.philosophers[i].thread, NULL) != 0) {
            perror("Failed to join thread");
            return 1;
        }
        i++;
    }

    destroy_philosophers_and_forks(&params);

    return 0;
}
