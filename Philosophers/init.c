/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:38:48 by yathayde          #+#    #+#             */
/*   Updated: 2024/06/04 09:38:53 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_params(t_dat *dat, char **argv)
{
	int	i;

	dat->n_philos = ft_atoi(argv[1]);
	dat->time_to_die = ft_atoi(argv[2]) * 1000;
	dat->time_to_eat = ft_atoi(argv[3]) * 1000;
	dat->time_to_sleep = ft_atoi(argv[4]) * 1000;
	dat->n_meals = 0;
	dat->max_meals = -1;
	if (argv[5])
		dat->max_meals = ft_atoi(argv[5]);
	dat->forks = malloc(sizeof(pthread_mutex_t) * dat->n_philos);
	dat->print = malloc(sizeof(pthread_mutex_t));
	dat->loopm = malloc(sizeof(pthread_mutex_t));
	dat->meals = malloc(sizeof(pthread_mutex_t));
	i = -1;
	while (++i < dat->n_philos)
		pthread_mutex_init(&dat->forks[i], NULL);
	pthread_mutex_init(dat->print, NULL);
	pthread_mutex_init(dat->loopm, NULL);
	pthread_mutex_init(dat->meals, NULL);
	dat->loop = 0;
}

t_philo	*init_philos(t_dat *dat)
{
	int		i;
	t_philo	*philos;

	philos = NULL;
	philos = malloc(sizeof(t_philo) * dat->n_philos);
	i = -1;
	dat->init_time = time_us();
	while (++i < dat->n_philos)
	{
		philos[i].dat = dat;
		philos[i].id = i + 1;
		philos[i].r_fork = &philos->dat->forks[right_fork(philos[i])];
		philos[i].l_fork = &philos->dat->forks[i];
		philos[i].l_eat = time_us();
		pthread_create(&philos[i].thid, NULL, routine, &(philos[i]));
	}
	return (philos);
}
