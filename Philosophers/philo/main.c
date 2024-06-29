/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yathayde <yathayde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:38:59 by yathayde          #+#    #+#             */
/*   Updated: 2024/06/29 11:14:46 by yathayde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	terminate_philos(t_philo *philo, int np)
{
	while (np-- > 0)
		pthread_join(philo[np].thid, NULL);
}

static unsigned long	in_time(t_philo philo)
{
	unsigned long	ret;

	ret = philo.l_eat + philo.dat->time_to_die;
	return (ret);
}

static int	check_death(t_philo *philos)
{
	int				philo;
	unsigned long	time;

	philo = 0;
	philo = philos[philo].dat->n_philos - 1;
	while (philo >= 0)
	{
		pthread_mutex_lock(philos[philo].dat->loopm);
		time = in_time(philos[philo]);
		pthread_mutex_unlock(philos[philo].dat->loopm);
		if (time < time_us())
		{
			time = time_us();
			pthread_mutex_lock(philos->dat->print);
			kill(philos->dat);
			printf("%05ld %i is dead\n",
				(time - philos->dat->init_time) / 1000, philos[philo].id);
			pthread_mutex_unlock(philos->dat->print);
			return (1);
		}
		philo--;
	}
	return (0);
}

static void	check_simulation(t_philo *philos)
{
	while (42)
	{
		if (check_meals(philos->dat) >= philos->dat->n_philos)
		{
			kill (philos->dat);
			return ;
		}
		if (check_death(philos))
			return ;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	t_dat		dat;
	t_philo		*philos;

	if (argc > 4 && argc < 7)
	{
		if (!check_entry(argv))
		{
			printf("Error: parameters should be integers greater than 0.\n");
			return (1);
		}
		init_params(&dat, argv);
		philos = init_philos(&dat);
		check_simulation(philos);
		terminate_philos(philos, dat.n_philos);
		ft_free(philos);
	}
	else
	{
		printf("Wrong number os parameters.\n");
		return (1);
	}
	return (0);
}
